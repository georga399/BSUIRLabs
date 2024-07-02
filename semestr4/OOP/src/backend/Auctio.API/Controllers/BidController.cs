using System.Security.Claims;
using Auctio.API.Hubs;
using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using Microsoft.AspNetCore.SignalR;

namespace Auctio.API.Controllers;

[Authorize]
[Route("api/[controller]")]
[ApiController]
public class BidController : ControllerBase
{
    private readonly IBidService _bidService;
    private readonly IHubContext<AuctionHub> _hubContext;
    private readonly IMapper _mapper;
    public BidController(IBidService bidService, IHubContext<AuctionHub> hubContext, IMapper mapper)
    {
        _bidService = bidService;
        _hubContext = hubContext;
        _mapper = mapper;
    }

    [HttpGet("allmybids")]
    public async Task<IActionResult> GetAllCurUserBids()
    {
        var username = User.FindFirst(ClaimTypes.Name)!.Value;  
        var bids = await _bidService.GetBidsByUserAsync(username);
        var dtos = _mapper.Map<IEnumerable<DTOs.Bid>>(bids); 
        return Ok(dtos);
    }

    [HttpGet("item/{itemid:guid}")]
    public async Task<IActionResult> GetBidsByItem(Guid itemid)
    {
        var bids = await _bidService.GetBidsByItemAsync(itemid);
        if(bids == null)
            return NotFound();

        var dtos = _mapper.Map<IEnumerable<DTOs.Bid>>(bids); 
        return Ok(dtos);
    }

    [Authorize(Roles ="Admin,Staff")]
    [HttpGet("user/{username}")]
    public async Task<IActionResult> GetBidsByUser(string username)
    {
        var bids = await _bidService.GetBidsByUserAsync(username);
        if(bids == null)
            return NotFound();
        return Ok(bids);

    }

    [Authorize]
    [HttpPost("makebid/item/{itemid:guid}")]
    public async Task<IActionResult> MakeBid(Guid itemid, decimal amount )
    {
        string username = User.FindFirst(ClaimTypes.Name)!.Value;
        var (success, bid) = await _bidService.CreateBidAsync(amount, username, itemid);
        if(!success)
            return BadRequest("");
        
        var dto = _mapper.Map<DTOs.Bid>(bid);
        await _hubContext.Clients.All.SendAsync("UpdateLastBid", dto);

        return Ok(bid);
    }

    [Authorize]
    [HttpDelete("{bidid:guid}")]
    public async Task<IActionResult> DeleteBid(Guid bidid)
    {
        string username = User.FindFirst(ClaimTypes.Name)!.Value;
        var (success, lastBid) = await _bidService.DeleteBidAsync(bidid, username);
        if(!success)
            return BadRequest();
        
        var dto = _mapper.Map<DTOs.Bid>(lastBid);
        await _hubContext.Clients.All.SendAsync("UpdateLastBid", dto);
        return Ok();
    }
}