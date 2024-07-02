using AutoMapper;

namespace Auctio.API.Profiles;
public class BidProfile: Profile
{
    private readonly IUserService _userService;
    public BidProfile(
        IUserService userService
        )
    {
        _userService = userService;
        CreateMap<Bid, DTOs.Bid>()
        .ForMember(dst => dst.ItemId, opt => opt.MapFrom(x=>x.ItemId))
        .ForMember(dst => dst.UserId, opt => opt.MapFrom(x => x.UserId))
        .ForMember( dst => dst.Username, opt => opt.MapFrom(
            x => _userService.GetUserName(x.UserId).Result
        ))
        .ForMember(dst => dst.DateTime, opt => opt.MapFrom(x => x.DateTime))
        .ForMember(dst => dst.Amount, opt => opt.MapFrom(x => x.Amount));

        CreateMap<DTOs.Bid, Bid>();
    }
}