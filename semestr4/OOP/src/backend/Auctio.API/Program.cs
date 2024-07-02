using Auctio.API;
using Auctio.API.Hubs;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSignalR();
builder.Services.AddSingleton<AuctionHub>();

builder.Services.ConfigureMySwagger();
builder.Services.AddUseCases();
builder.Services.AddPersistense();
builder.Services.AddMyAuthentication();

builder.Services.ConfigureMappers();


var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();
app.MapHub<AuctionHub>("/hub");

app.Run();
