using AutoMapper;

namespace Auctio.API.Profiles;
public class CategoryProfile: Profile
{
    public CategoryProfile()
    {
        CreateMap<Category, DTOs.Category>()
        .ForMember(dst => dst.Name, opt => opt.MapFrom(x=>x.Name))
        .ForMember(dst => dst.Id, opt => opt.MapFrom(x => x.Id));

        CreateMap<DTOs.Category, Category>();
    }
}