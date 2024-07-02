using System.Security.Claims;
using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Auctio.API.Controllers;

[Authorize]
[Route("api/[controller]")]
[ApiController]
public class UserController : ControllerBase
{
    private readonly IUserService _userService;
    private readonly IMapper _mapper;
    public UserController(IUserService userService, IMapper mapper)
    {
        _userService = userService;        
        _mapper = mapper;
    }
    [HttpGet("")]
    public async Task<IActionResult> MyDetails()
    {
        var userid = User.FindFirst(ClaimTypes.NameIdentifier)!.Value;
        var userbyid = await _userService.GetUserById(new Guid(userid));
        var dto = _mapper.Map<User, DTOs.UserDetails>(userbyid);
        return Ok(dto);
    }
    // [Authorize(Roles = "Staff,Admin")]
    [HttpGet("{username}")]
    public async Task<IActionResult> UserDetails(string username)
    {
        var user = await _userService.GetUser(username);
        if(user == null)
        {
            return NotFound(username);
        }
        var dto = _mapper.Map<User, DTOs.UserDetails>(user);
        return Ok(dto);
    }

}
