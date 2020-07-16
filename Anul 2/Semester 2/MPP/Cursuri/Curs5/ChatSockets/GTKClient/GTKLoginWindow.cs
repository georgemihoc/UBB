using System;
using Gtk;
namespace GTKClient
{
    public class LoginWindow : Window
    {
        private GTKClientCtrl ctrl;
        Entry username, password;
        Button login, cancel;
        public LoginWindow(GTKClientCtrl ctrl) : base("Chat XYZ Login")
        {
            this.ctrl = ctrl;
            SetDefaultSize(300,300);
            SetPosition(WindowPosition.Center);
            DeleteEvent += CloseWindow;
            
            VBox vbox = new VBox(false, 2);
            Table table = new Table(4, 4, false);

            table.Attach(new Label("Chat XYZ"), 0, 4, 0, 1);
            table.Attach(new Label("Username"), 0, 2, 1, 2);
            table.Attach(username=new Entry(), 2, 4, 1, 2);
                       
            table.Attach(new Label("Password"), 0, 2, 2, 3);
            table.Attach(password=new Entry(), 2, 4, 2, 3);
            password.Visibility=false;
                       
            table.Attach(cancel=new Button("Clear"), 0, 2, 3, 4);
            table.Attach(login=new Button("Login"), 2, 4, 3, 4);

            login.Clicked += loginButtonPressed;
            cancel.Clicked += cancelButtonPressed;

            vbox.PackEnd(table, true, true, 0);
        
                       
            Add(vbox);
           
        }

        void CloseWindow(Object o, DeleteEventArgs args)
        {
           // ctrl.logout();
            Console.WriteLine("Application closing");
            Application.Quit();
        }
        
         void loginButtonPressed(object sender, EventArgs e)
        {
            Console.WriteLine("S-a apasat login");
            Console.WriteLine("Username {0} - Password - {1}",username.Text, password.Text);
            String user = username.Text;
            String pass = password.Text;
            try
            {
                ctrl.login(user, pass);
               // MessageDialog md = new MessageDialog(this, DialogFlags.DestroyWithParent, MessageType.Info, ButtonsType.Ok, "Autentificare reusita");
                //md.Run();
                //md.Dispose();
                //MessageBox.Show("Login succeded");
                ChatWindow chatWin=new ChatWindow(ctrl, "Chat window for " + user);
                //chatWin.Text = "Chat window for " + user;
                chatWin.ShowAll();
                Dispose();
            }catch(Exception ex)
            {
                MessageDialog md = new MessageDialog(this, DialogFlags.DestroyWithParent, MessageType.Error, ButtonsType.Close, "Eroare la autentificare");
                md.Run();
                md.Dispose();
                return;
            }
            
            /*MessageDialog md = new MessageDialog(this, 
                DialogFlags.DestroyWithParent, MessageType.Error, 
                ButtonsType.Ok, "Eroare la autentitficare");
            md.Run();
            md.Destroy();*/
            
        }

         void cancelButtonPressed(object sender, EventArgs e)
         {
             username.Text = "";
             password.Text = "";
             // Application.Quit();
         }
    }
}