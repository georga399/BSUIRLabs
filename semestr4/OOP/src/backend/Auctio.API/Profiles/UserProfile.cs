using AutoMapper;

namespace Auctio.API.Profiles;
public class UserProfile: Profile
{
    public UserProfile()
    {
        CreateMap<User, DTOs.UserDetails>()
        .ForMember(dst => dst.Username, opt => opt.MapFrom(x=>x.Name))
        .ForMember(dst => dst.Id, opt => opt.MapFrom(x => x.Id));
        CreateMap<DTOs.UserDetails, User>();
    }
}