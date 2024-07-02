
using System.Security.Claims;
using Microsoft.AspNetCore.SignalR;

namespace Auctio.API.Hubs;

public class AuctionHub : Hub
{
    public override async Task OnConnectedAsync()
    {
        var userrole = Context.User!.FindFirst(ClaimTypes.Role)?.Value;

        if (userrole != null && (userrole == "Admin" || userrole == "Staff"))
        {
            await Groups.AddToGroupAsync(Context.ConnectionId, "staff");
        } 
        else if (userrole == "User")
        {
            await Groups.AddToGroupAsync(Context.ConnectionId, "user");
        }
        await Clients.All.SendAsync("NewConnection");
        await base.OnConnectedAsync();
    }
    public override async Task OnDisconnectedAsync(Exception? exception)
    {
        await base.OnDisconnectedAsync(exception);
    }
}
