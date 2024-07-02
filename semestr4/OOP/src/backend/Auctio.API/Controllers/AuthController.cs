using Auctio.Core.Domain.Abstractions;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Auctio.API.Controllers;
[Route("api/[controller]")]
[ApiController]
public class AuthController : ControllerBase
{
    private readonly IAuthService _authService;
    public AuthController(IAuthService authService)
    {
        _authService = authService;
    }

    [HttpPost("login")]
    public async Task<IActionResult> Login([FromBody] DTOs.AuthModel authModel)
    {
        var (success, token) = await _authService.SignIn(authModel.Username, authModel.Password);
        if (!success)
        {
            return Unauthorized("Username or password are incorrect.");
        }
        return Ok(new { Token = token });
    }
    [HttpPost("register")]
    public async Task<IActionResult> Register([FromBody] DTOs.AuthModel authModel)
    {
        var (success, userId) = await _authService.Register(authModel.Username, authModel.Password);
        if(!success)
        {
            return BadRequest("User already exists.");
        }
        return Ok("Successful registration.");
    }
}
