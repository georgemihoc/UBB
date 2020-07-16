using System;
using Gtk;
using chat.services;
using chat.network.server;
namespace GTKClient
{
    internal class StartGTKClient
    
    {
        public static void Main(string[] args)
        {
            Application.Init ();
            IChatServices server = new ChatServerProxy("127.0.0.1", 55555);
            GTKClientCtrl ctrl=new GTKClientCtrl(server);
           Window w=new LoginWindow(ctrl);
          // Window w = new ChatWindow();
            w.ShowAll();
            Application.Run ();
                        
        }
    }
}