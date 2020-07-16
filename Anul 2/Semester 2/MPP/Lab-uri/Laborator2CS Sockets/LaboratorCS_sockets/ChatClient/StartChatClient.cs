using System;
using System.Windows.Forms;
using swim.services;
using swim.network.server;
using swim.services;
using swim.server;

namespace swim.client
{
    static class StartChatClient
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //IChatServer server=new ChatServerMock();          
            IServices server = new ChatServerProxy("127.0.0.1", 55555);
            ChatClientCtrl ctrl=new ChatClientCtrl(server);
            MainView windows = new MainView(ctrl);
            //LoginWindow win=new LoginWindow(ctrl);
            Application.Run(windows);
        }
    }
}
