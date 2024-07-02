using System.Security.Claims;
using Auctio.API.Hubs;
using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.SignalR;

namespace Auctio.API.Controllers;

[Route("api/[controller]")]
[ApiController]
public class ItemController : ControllerBase
{
    private readonly IItemService _itemService;
    private readonly IHubContext<AuctionHub> _hubContext;
    private readonly IMapper _mapper;
    public ItemController(IItemService itemService, IHubContext<AuctionHub> hubContext, IMapper mapper)
    {
        _itemService = itemService;
        _hubContext = hubContext;
        _mapper = mapper;
    }
    
    [HttpGet("bycategory/{catname}")]
    public async Task<IActionResult> GetItemsByCategory(string catname)
    {
        var items = await _itemService.GetItemsByCategoryAsync(catname);
        if(items == null)
            return NotFound($"category {catname} not found");

        var dtos = _mapper.Map<IEnumerable<Item>, IEnumerable<DTOs.Item>>(items);
        return Ok(dtos);
    }

    [HttpGet("{itemid:guid}")]
    public async Task<IActionResult> GetItemDetails(Guid itemid)
    {
        var item = await _itemService.GetItemAsync(itemid);
        if (item == null)
            return NotFound();
        var dto = _mapper.Map<Item, DTOs.Item>(item);
        return Ok(dto);
    }

    [Authorize(Roles="Admin,Staff")]
    [HttpGet("postedby/{username}")]
    public async Task<IActionResult> GetItemsByUser(string username)
    {
        var items = await _itemService.GetItemsByUserAsync(username);
        if(items == null)
            return NotFound();
        var dtos = _mapper.Map<IEnumerable<Item>, IEnumerable<DTOs.Item>>(items);
        return Ok(dtos);
    }

    [Authorize]
    [HttpGet("myposted")]
    public async Task<IActionResult> GetItemsByCurUser()
    {
        var userid = User.FindFirst(ClaimTypes.NameIdentifier)!.Value;
        var items = await _itemService.GetItemsByUserIdAsync(new Guid(userid));
        var dtos = _mapper.Map<IEnumerable<Item>, IEnumerable<DTOs.Item>>(items);
        return Ok(dtos);
    }

    [Authorize]
    [HttpPost("create")]
    public async Task<IActionResult> CreateItem(DTOs.Item request)
    {
        var username = User.FindFirst(ClaimTypes.Name)!.Value;
        var (success, item) = await _itemService.CreateItemAsync(
            request.Title,
            username,
            request.Description,
            request.CategoryName,
            request.StartingPrice,
            request.MinIncreasePrice,
            request.StartTime,
            request.EndTime
        ); 
        if(!success)
            return BadRequest("");
        
        var dto = _mapper.Map<DTOs.Item>(item);
        
        await _hubContext.Clients.Group("staff").SendAsync("RecieveItem", dto);
        return Ok(dto);

    }

    [Authorize]
    [HttpPut("{itemid:guid}/editdetails")]
    public async Task<IActionResult> ChangeItemDetails(Guid itemid, DTOs.Item item)
    {
        var username = User.FindFirst(ClaimTypes.Name)!.Value;
        var (success, resitem) = await _itemService.ChangeItemDetailsAsync(itemid, 
            new Item()
            {
                Title=item.Title,
                Description=item.Description,
                StartingPrice=item.StartingPrice,
                MinIncrease=item.MinIncreasePrice,
                StartTime=item.StartTime,
                EndTime=item.EndTime
            },
            username
        );
        if(!success)
            return BadRequest();
        var dto = _mapper.Map<DTOs.Item>(resitem);

        await _hubContext.Clients.Group("staff").SendAsync("EditItemDetails", dto);
        return Ok(dto);
    }

    [Authorize(Roles="Admin,Staff")]
    [HttpPut("{itemid:guid}/editstatus/{itemstatus:int}")]
    public async Task<IActionResult> ChangeItemStatus(Guid itemid, int itemstatus)
    {
        var (success, item) = await _itemService.ChangeItemStatusAsync(itemid, (ItemStatus)itemstatus);
        if(!success)
            return BadRequest();
        
        var dto = _mapper.Map<DTOs.Item>(item);

        await _hubContext.Clients.Group("staff").SendAsync("EditItemStatus", dto);
        return Ok(dto);
    }

    [Authorize]
    [HttpPut("{itemid:guid}/finish")]
    public async Task<IActionResult> FinishItem(Guid itemid)
    {
        var username = User.FindFirst(ClaimTypes.Name)!.Value;
        var (success, item) = await _itemService.CloseItemAsync(itemid, username);
        if(!success)
            return BadRequest();
        var dto = _mapper.Map<DTOs.Item>(item);

        await _hubContext.Clients.All.SendAsync("FinishItem", dto);
        return Ok(item);
    }

    [Authorize]
    [HttpDelete("{itemid:guid}/delete")]
    public async Task<IActionResult> DeleteItem(Guid itemid)
    {
        var username = User.FindFirst(ClaimTypes.Name)!.Value;
        var success = await _itemService.DeleteItemAsync(itemid, username);
        if(!success)
            return BadRequest();
        return Ok();
    }
}
