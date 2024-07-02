using AutoMapper;

namespace Auctio.API.Profiles;
public class ItemProfile: Profile
{
    private readonly IUserService _userService;
    private readonly ICategoryService _categoryService;
    private readonly IBidService _bidService;
    public ItemProfile(
        IUserService userService, ICategoryService categoryService, IBidService bidService
        )
    {
        _userService = userService; 
        _categoryService = categoryService;
        _bidService = bidService;

        CreateMap<Item, DTOs.Item>()
        .ForMember(dst => dst.Title, opt => opt.MapFrom(x=>x.Title))
        .ForMember(dst => dst.Id, opt => opt.MapFrom(x => x.Id))
        .ForMember(dst => dst.CategoryName, opt => opt.MapFrom(
            x => _categoryService.GetCategoryName(x.CategoryId).Result
        ))
        .ForMember(dst => dst.CategoryId, opt => opt.MapFrom(x => x.CategoryId))
        .ForMember(dst => dst.UserId, opt => opt.MapFrom(x => x.UserId))
        .ForMember(dst => dst.Username, opt => opt.MapFrom(
            x => _userService.GetUserName(x.UserId).Result
        ))
        .ForMember(dst => dst.StartingPrice, opt => opt.MapFrom(x => x.StartingPrice))
        .ForMember(dst => dst.MinIncreasePrice, opt => opt.MapFrom(x => x.MinIncrease))
        .ForMember(dst => dst.StartTime, opt => opt.MapFrom(x => x.StartTime))
        .ForMember(dst => dst.EndTime, opt => opt.MapFrom(x => x.EndTime))
        .ForMember(dst => dst.ItemStatus, opt => opt.MapFrom(x => x.ItemStatus))
        .ForMember(dst => dst.LastBid, opt => opt.MapFrom(
            x => _bidService.GetLastBidAsync(x.Id).Result
        ))
        ;

        CreateMap<DTOs.Item, Item>();
    }
}