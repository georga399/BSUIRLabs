using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.VisualBasic;

namespace Auctio.API.Controllers;

[Route("api/[controller]")]
[ApiController]
public class CategoryController : ControllerBase
{
    private readonly ICategoryService _categoryService;
    private readonly IMapper _mapper;
    public CategoryController(ICategoryService categoryService, IMapper mapper)
    {
        _categoryService = categoryService;
        _mapper = mapper;
    }

    [HttpGet("all")]
    public async Task<IActionResult> GetAll()
    {
        var cats = await _categoryService.GetAllAsync();
        var dtos = _mapper.Map<IEnumerable<Category>, IEnumerable<DTOs.Category>>(cats);
        return Ok(dtos);
    }
    
    [HttpGet("{categoryname}")]
    public async Task<IActionResult> GetDetails(string categoryname)
    {
        var cat = await _categoryService.GetCategoryAsync(categoryname);
        if(cat != null)
        {
            var dto = _mapper.Map<Category, DTOs.Category>(cat);
            return Ok(dto);
        }
        return NotFound();
    }
    [Authorize(Roles = "Admin")]
    [HttpPost("create")]
    public async Task<IActionResult> Create([FromBody] DTOs.Category dto)
    {
        var (success, cat) = await _categoryService.CreateCategoryAsync(dto.Name);
        if(success)
        {
            var resdto = _mapper.Map<Category, DTOs.Category>(cat);
            return Ok(resdto);
        }
        return BadRequest();
    }
    [Authorize(Roles = "Admin")]
    [HttpPut("{catid:guid}")]
    public async Task<IActionResult> Edit(Guid catid, DTOs.Category cat)
    {
        var (success, category) = await _categoryService.ChangeCategoryAsync(catid, 
            new Category
            {
                Name = cat.Name
            }
        );
        if(!success)
            return BadRequest();
        return Ok(category);
    }

    [Authorize(Roles = "Admin")]
    [HttpDelete("{catid:guid}")]
    public async Task<IActionResult> Delete(Guid catid)
    {
        var success = await _categoryService.DeleteCategoryAsync(catid);
        if(success)
        {
            return Ok($"Category {catid} was deleted.");
        }
        return BadRequest();
    }
}
