using DiscordRPC;

namespace Netherite.Handlers
{
    internal class RPCHandler
    {
        public static DiscordRpcClient client;
        public static void Initialize()
        {
            client = new DiscordRpcClient("919369176550875198");
            client.Initialize();
        }

        public static void Setup()
        {
            client.SetPresence(new RichPresence()
            {
                State = "",
                Timestamps = Timestamps.Now,
                Assets = new Assets
                {
                    LargeImageText = "Netherite Client V2",
                    SmallImageText = "Minecraft: Bedrock Edition",
                    LargeImageKey = "icon",
                    SmallImageKey = "mcbe"
                }
            });
        }

        public static void WipePresence()
        {
            client.ClearPresence();
            //client.Dispose();
        }
    }
}
