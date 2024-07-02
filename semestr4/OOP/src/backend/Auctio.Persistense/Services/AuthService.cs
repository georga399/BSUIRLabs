using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using Auctio.Core.Domain.Abstractions;
using Auctio.Core.Domain.Entities;
using Auctio.Persistense.Data;
using Auctio.Persistense.Repository;
using Auctio.Persistense.UnitOfWork;
using Microsoft.IdentityModel.Tokens;

namespace Auctio.Persistense;

public class AuthService : IAuthService
{
    private readonly IUnitOfWork _unitOfWork;
    private readonly IRepository<User> _userRepository;
    private readonly PasswordHasher _passwordHasher;
    public AuthService(IUnitOfWork unitOfWork)
    {
        _unitOfWork = unitOfWork;
        _userRepository = unitOfWork.UserRepository;
        _passwordHasher = new PasswordHasher();
    }
    public async Task<(bool, Guid)> Register(string username, string password)
    {
        
        var user  = await _userRepository.FirstOrDefaultAsync(u => u.Name == username);
        if (user != null)
        {
            return (false, Guid.Empty);
        }
        // var parts = hashedPassword.Split(new[] { ':' }, 2);
        user = new User()
        {
            Name = username,
            PassHash = _passwordHasher.Hash(password),
            // PassSalt = salt,
            // PassHash = parts[0],
            // PassSalt = parts[1],
            Role = UserRole.User
        };
        await _userRepository.AddAsync(user);
        await _unitOfWork.SaveAllAsync();
        return (true, user.Id);
    }
    public async Task<(bool, string)> SignIn(string username, string password)
    {
        var user = await _userRepository.FirstOrDefaultAsync(u => u.Name == username);
        if(user == null || !_passwordHasher.Verify(user.PassHash, password))
        {
            return (false, string.Empty);
        }
        var token = GenerateJwtToken(user);
        return (true, token);
    }
    private string GenerateJwtToken(User user)
    {
        var tokenHandler = new JwtSecurityTokenHandler();
        var key = Encoding.UTF8.GetBytes("yourSuperSuperSuperSecretKey123!@#");
        var tokenDescriptor = new SecurityTokenDescriptor
        {
            Subject = new ClaimsIdentity(new Claim[]
            {
                new Claim(ClaimTypes.NameIdentifier, user.Id.ToString()),
                new Claim(ClaimTypes.Name, user.Name),
                new Claim(ClaimTypes.Role, user.Role.ToString())
            }),
            Expires = DateTime.UtcNow.AddHours(1),
            Issuer = "yourIssuer",
            Audience = "yourAudience",
            SigningCredentials = new SigningCredentials(new SymmetricSecurityKey(key), SecurityAlgorithms.HmacSha256Signature)
        };
        var token = tokenHandler.CreateToken(tokenDescriptor);
        return tokenHandler.WriteToken(token);
    }
}