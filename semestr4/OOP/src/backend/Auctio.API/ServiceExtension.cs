using System.Text;
using Auctio.API.Profiles;
using Auctio.Core.UseCases;
using Auctio.Persistense;
using Auctio.Persistense.Data;
using Auctio.Persistense.UnitOfWork;
using AutoMapper;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;

namespace Auctio.API;

public static class ServiceExtension
{
    public static IServiceCollection AddPersistense(this IServiceCollection services)
    {
        services.AddSingleton<AppDbContext>();
        services.AddSingleton<IUnitOfWork, EfUnitOfWork>();
        DbInitializer.Initialize(services).Wait();
        return services;
    }
    public static IServiceCollection AddUseCases(this IServiceCollection services)
    {
        services.AddSingleton<IAuthService, AuthService>();
        services.AddSingleton<IUserService, UserService>();
        services.AddSingleton<ICategoryService, CategoryService>();
        services.AddSingleton<IItemService, ItemService>();
        services.AddSingleton<IBidService, BidService>();
        return services;
    }
    public static IServiceCollection AddMyAuthentication(this IServiceCollection services)
    {
        services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
        .AddJwtBearer(options =>
        {
            options.TokenValidationParameters = new TokenValidationParameters
            {
                ValidateIssuer = true,
                ValidateAudience = true,
                ValidateLifetime = true,
                ValidateIssuerSigningKey = true,
                ValidIssuer = "yourIssuer",
                ValidAudience = "yourAudience",
                IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes("yourSuperSuperSuperSecretKey123!@#"))
            };
        });
        return services;
    }

    public static IServiceCollection ConfigureMySwagger(this IServiceCollection services)
    {
        services.AddSwaggerGen(c => 
        {
            c.SwaggerDoc("v1", new OpenApiInfo { Title = "Auctio.API", Version = "v1" });

                // Add the JWT Bearer security scheme
            c.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
            {
                Description = "JWT Authorization header using the Bearer scheme. Example: \"Authorization: Bearer {token}\"",
                Name = "Authorization",
                In = ParameterLocation.Header,
                Type = SecuritySchemeType.ApiKey
            });
            // Add the JWT Bearer authentication to the Swagger operations
            c.AddSecurityRequirement(new OpenApiSecurityRequirement
            {
                {
                    new OpenApiSecurityScheme
                    {
                        Reference = new OpenApiReference
                        {
                            Type = ReferenceType.SecurityScheme,
                            Id = "Bearer"
                        }
                    },
                    new string[] { }
                }
            });

        });
        return services;
    }

    public static IServiceCollection ConfigureMappers(this IServiceCollection services)
    {
        services.AddAutoMapper(
            typeof(UserProfile),
            typeof(CategoryProfile),
            typeof(BidProfile),
            typeof(ItemProfile)

        );
        services.AddSingleton(provider => new MapperConfiguration(cfg =>
        {
            cfg.AddProfile(new UserProfile());
            cfg.AddProfile(new CategoryProfile());
            cfg.AddProfile(new BidProfile(
                provider.GetService<IUserService>()!
            ));
            cfg.AddProfile(new ItemProfile(
                provider.GetService<IUserService>()!,
                provider.GetService<ICategoryService>()!,
                provider.GetService<IBidService>()!
            ));
        }).CreateMapper());

        return services;
    }
}