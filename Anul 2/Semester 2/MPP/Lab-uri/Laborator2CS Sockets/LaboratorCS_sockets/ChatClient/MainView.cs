using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using swim.model;
using swim.server;


namespace swim.client
{
    public partial class MainView : Form
    {
        private Label labelProbe;
        private Panel mainPane;
        private ListBox listViewProbe;
        private CheckedListBox checkedListBoxProbe;
        private TextBox textBoxVarsta;
        private TextBox textBoxNume;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label1;
        private Label labelParticipanti;
        private ListBox listViewParticipanti;
        private Button buttonLogout;
        private Button buttonAdd;
        private Button buttonRefresh;
        private Panel loginPane;
        private MaskedTextBox textPassword;
        private TextBox textUsername;
        private Label label7;
        private Label label6;
        private Label label5;
        private Button button1;
        ChatClientCtrl ctrl;
        IList<string> organizatoriData;
        IList<Proba> probaData;
        IList<Participant> participantData;
        IList<Inscriere> inscriereData;

        //private
        //SwimServerImpl server;
        //Service _service;
        public MainView(ChatClientCtrl ctrl)
        {
            InitializeComponent();

            this.ctrl = ctrl;

            
            //this.server = server;
            //loginPane.Show();
            mainPane.Hide();

            ctrl.updateEvent += userUpdate;

        }

        private void LoadListViewTable()
        {//REZOLVAT
            
            //var listaOrganizatori = ctrl.getLoggedFriends();

            ////var probe = _service.GetAllProba();
            //var probe = server.getAllProba();
            //listViewProbe.Items.Clear(); 

            //foreach (var p in probe)
            //{
            //    var row = p.IdProba.ToString() + " | " + p.Lungime.ToString() + " | " + p.Stil + " | " + p.NrParticipanti + " participantibaaaa";
            //    listViewProbe.Items.Add(row);


            //}
        }

        private void probeForm_Load(object sender, EventArgs e)
        {
            LoadListViewTable();
            LoadCheckBoxProbe();
        }
        private void LoadCheckBoxProbe()
        {
            //Console.WriteLine("boss");
            ////var probe = _service.GetAllProba();
            //var probe = server.getAllProba();
            //checkedListBoxProbe.Items.Clear();

            //foreach (var p in probe)
            //{
            //    var row = p.Lungime.ToString() + " | " + p.Stil;

            //    checkedListBoxProbe.Items.Add(row);

            //}
        }
        private void probeCheckbox_Load(object sender, EventArgs e)
        {
            LoadCheckBoxProbe();
        }

        public void userUpdate(object sender, ChatUserEventArgs e)
        {
            //if (e.UserEventType == ChatUserEvent.FriendLoggedIn)
            //{
            //    String friendId = e.Data.ToString();
            //    friendsData.Add(friendId);
            //    Console.WriteLine("[ChatWindow] friendLoggedIn " + friendId);
            //    friendList.BeginInvoke(new UpdateListBoxCallback(this.updateListBox), new Object[] { friendList, friendsData });
            //    //   friendList.BeginInvoke((Action) delegate { friendList.DataSource = friendsData; });

            //}
            //if (e.UserEventType == ChatUserEvent.FriendLoggedOut)
            //{
            //    String friendId = e.Data.ToString();
            //    friendsData.Remove(friendId);
            //    Console.WriteLine("[ChatWindow] friendLoggedOut " + friendId);
            //    friendList.BeginInvoke(new UpdateListBoxCallback(this.updateListBox), new Object[] { friendList, friendsData });
            //}
            if (e.UserEventType == ChatUserEvent.ParticipantAdaugat)
            {
                //loadComponents();
                //Inscriere inscriere = e.Data.GetType();
                //messageData.Add(messString);
                //Console.WriteLine("[ChatWindow] messString " + messString);
                string inscriere = e.Data.ToString();
                Console.WriteLine(inscriere);
                string idInscriere = inscriere.Substring(inscriere.Length - 1);
                foreach (var proba in probaData)
                {
                    if(proba.IdProba == Int32.Parse(idInscriere))
                    {
                        proba.NrParticipanti = proba.NrParticipanti + 1;
                    }
                }

                inscriereData.Add(new Inscriere(Int32.Parse(inscriere.Substring(0, 1)), Int32.Parse(inscriere.Substring(2, 3)), Int32.Parse(idInscriere)));
                //probaData.Add((Inscriere)inscriere);
                listViewProbe.BeginInvoke(new UpdateListBoxCallback(this.updateListBox), new Object[] { listViewProbe, probaData });
                //participantData = ctrl.getParticipanti();
            }
        }
        //for updating the GUI

        //1. define a method for updating the ListBox
        private void updateListBox(ListBox listBox, IList<Proba> newData)
        {
            listBox.DataSource = null;
            listBox.DataSource = newData;
        }

        //2. define a delegate to be called back by the GUI Thread
        public delegate void UpdateListBoxCallback(ListBox list, IList<Proba> data);

        private void InitializeComponent()
        {
            this.labelProbe = new System.Windows.Forms.Label();
            this.mainPane = new System.Windows.Forms.Panel();
            this.buttonLogout = new System.Windows.Forms.Button();
            this.buttonAdd = new System.Windows.Forms.Button();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.checkedListBoxProbe = new System.Windows.Forms.CheckedListBox();
            this.textBoxVarsta = new System.Windows.Forms.TextBox();
            this.textBoxNume = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.labelParticipanti = new System.Windows.Forms.Label();
            this.listViewParticipanti = new System.Windows.Forms.ListBox();
            this.listViewProbe = new System.Windows.Forms.ListBox();
            this.loginPane = new System.Windows.Forms.Panel();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textUsername = new System.Windows.Forms.TextBox();
            this.textPassword = new System.Windows.Forms.MaskedTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.mainPane.SuspendLayout();
            this.loginPane.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelProbe
            // 
            this.labelProbe.AutoSize = true;
            this.labelProbe.Location = new System.Drawing.Point(3, 39);
            this.labelProbe.Name = "labelProbe";
            this.labelProbe.Size = new System.Drawing.Size(69, 25);
            this.labelProbe.TabIndex = 1;
            this.labelProbe.Text = "Probe";
            // 
            // mainPane
            // 
            this.mainPane.Controls.Add(this.buttonLogout);
            this.mainPane.Controls.Add(this.buttonAdd);
            this.mainPane.Controls.Add(this.buttonRefresh);
            this.mainPane.Controls.Add(this.checkedListBoxProbe);
            this.mainPane.Controls.Add(this.textBoxVarsta);
            this.mainPane.Controls.Add(this.textBoxNume);
            this.mainPane.Controls.Add(this.label4);
            this.mainPane.Controls.Add(this.label3);
            this.mainPane.Controls.Add(this.label2);
            this.mainPane.Controls.Add(this.label1);
            this.mainPane.Controls.Add(this.labelParticipanti);
            this.mainPane.Controls.Add(this.listViewParticipanti);
            this.mainPane.Controls.Add(this.listViewProbe);
            this.mainPane.Controls.Add(this.labelProbe);
            this.mainPane.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainPane.Location = new System.Drawing.Point(0, 0);
            this.mainPane.Name = "mainPane";
            this.mainPane.Size = new System.Drawing.Size(1090, 786);
            this.mainPane.TabIndex = 2;
            // 
            // buttonLogout
            // 
            this.buttonLogout.Location = new System.Drawing.Point(4, 13);
            this.buttonLogout.Name = "buttonLogout";
            this.buttonLogout.Size = new System.Drawing.Size(151, 28);
            this.buttonLogout.TabIndex = 14;
            this.buttonLogout.Text = "Logout";
            this.buttonLogout.UseVisualStyleBackColor = true;
            this.buttonLogout.MouseClick += new System.Windows.Forms.MouseEventHandler(this.handleLogout);
            // 
            // buttonAdd
            // 
            this.buttonAdd.Location = new System.Drawing.Point(869, 568);
            this.buttonAdd.Name = "buttonAdd";
            this.buttonAdd.Size = new System.Drawing.Size(107, 50);
            this.buttonAdd.TabIndex = 13;
            this.buttonAdd.Text = "Add";
            this.buttonAdd.UseVisualStyleBackColor = true;
            this.buttonAdd.MouseClick += new System.Windows.Forms.MouseEventHandler(this.handleAdd);
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.Location = new System.Drawing.Point(28, 608);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(107, 48);
            this.buttonRefresh.TabIndex = 12;
            this.buttonRefresh.Text = "Refresh";
            this.buttonRefresh.UseVisualStyleBackColor = true;
            this.buttonRefresh.MouseClick += new System.Windows.Forms.MouseEventHandler(this.handleRefresh);
            // 
            // checkedListBoxProbe
            // 
            this.checkedListBoxProbe.FormattingEnabled = true;
            this.checkedListBoxProbe.Location = new System.Drawing.Point(790, 370);
            this.checkedListBoxProbe.Name = "checkedListBoxProbe";
            this.checkedListBoxProbe.Size = new System.Drawing.Size(186, 172);
            this.checkedListBoxProbe.TabIndex = 11;
            // 
            // textBoxVarsta
            // 
            this.textBoxVarsta.Location = new System.Drawing.Point(790, 288);
            this.textBoxVarsta.Name = "textBoxVarsta";
            this.textBoxVarsta.Size = new System.Drawing.Size(186, 31);
            this.textBoxVarsta.TabIndex = 10;
            // 
            // textBoxNume
            // 
            this.textBoxNume.Location = new System.Drawing.Point(790, 215);
            this.textBoxNume.Name = "textBoxNume";
            this.textBoxNume.Size = new System.Drawing.Size(186, 31);
            this.textBoxNume.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(645, 357);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 25);
            this.label4.TabIndex = 8;
            this.label4.Text = "Probe:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(645, 288);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(80, 25);
            this.label3.TabIndex = 7;
            this.label3.Text = "Varsta:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(640, 215);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 25);
            this.label2.TabIndex = 6;
            this.label2.Text = "Nume:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(670, 113);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(94, 25);
            this.label1.TabIndex = 5;
            this.label1.Text = "Inscriere";
            // 
            // labelParticipanti
            // 
            this.labelParticipanti.AutoSize = true;
            this.labelParticipanti.Location = new System.Drawing.Point(313, 34);
            this.labelParticipanti.Name = "labelParticipanti";
            this.labelParticipanti.Size = new System.Drawing.Size(188, 25);
            this.labelParticipanti.TabIndex = 4;
            this.labelParticipanti.Text = "Participanti /Proba";
            // 
            // listViewParticipanti
            // 
            this.listViewParticipanti.FormattingEnabled = true;
            this.listViewParticipanti.ItemHeight = 25;
            this.listViewParticipanti.Location = new System.Drawing.Point(313, 65);
            this.listViewParticipanti.Name = "listViewParticipanti";
            this.listViewParticipanti.Size = new System.Drawing.Size(244, 454);
            this.listViewParticipanti.TabIndex = 3;
            // 
            // listViewProbe
            // 
            this.listViewProbe.FormattingEnabled = true;
            this.listViewProbe.ItemHeight = 25;
            this.listViewProbe.Location = new System.Drawing.Point(12, 67);
            this.listViewProbe.Name = "listViewProbe";
            this.listViewProbe.Size = new System.Drawing.Size(238, 454);
            this.listViewProbe.TabIndex = 2;
            this.listViewProbe.SelectedIndexChanged += new System.EventHandler(this.viewProbeSelected);
            // 
            // loginPane
            // 
            this.loginPane.Controls.Add(this.button1);
            this.loginPane.Controls.Add(this.textPassword);
            this.loginPane.Controls.Add(this.textUsername);
            this.loginPane.Controls.Add(this.label7);
            this.loginPane.Controls.Add(this.label6);
            this.loginPane.Controls.Add(this.label5);
            this.loginPane.Dock = System.Windows.Forms.DockStyle.Fill;
            this.loginPane.Location = new System.Drawing.Point(0, 0);
            this.loginPane.Name = "loginPane";
            this.loginPane.Size = new System.Drawing.Size(1090, 786);
            this.loginPane.TabIndex = 15;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(390, 113);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(65, 25);
            this.label5.TabIndex = 0;
            this.label5.Text = "Login";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(308, 284);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(116, 25);
            this.label6.TabIndex = 1;
            this.label6.Text = "Username:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(313, 381);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(112, 25);
            this.label7.TabIndex = 2;
            this.label7.Text = "Password:";
            // 
            // textUsername
            // 
            this.textUsername.Location = new System.Drawing.Point(470, 281);
            this.textUsername.Name = "textUsername";
            this.textUsername.Size = new System.Drawing.Size(169, 31);
            this.textUsername.TabIndex = 3;
            // 
            // textPassword
            // 
            this.textPassword.Location = new System.Drawing.Point(470, 381);
            this.textPassword.Name = "textPassword";
            this.textPassword.Size = new System.Drawing.Size(169, 31);
            this.textPassword.TabIndex = 4;
            this.textPassword.PasswordChar = '\u25CF';
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(509, 469);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(130, 50);
            this.button1.TabIndex = 5;
            this.button1.Text = "Login";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.handleLogin);
            // 
            // MainView
            // 
            this.ClientSize = new System.Drawing.Size(1090, 786);
            this.Controls.Add(this.loginPane);
            this.Controls.Add(this.mainPane);
            this.Name = "MainView";
            this.Load += new System.EventHandler(this.probeForm_Load);
            this.mainPane.ResumeLayout(false);
            this.mainPane.PerformLayout();
            this.loginPane.ResumeLayout(false);
            this.loginPane.PerformLayout();
            this.ResumeLayout(false);

        }

        public IEnumerable<Participant> findAllInscrisi(int idProba)
        {
            participantData = ctrl.getParticipanti();

            List<Participant> list = new List<Participant>();
            foreach (Inscriere inscriere in inscriereData)
            {
                if (inscriere.IdProba == idProba)
                {
                    foreach(var participant in participantData)
                    {
                        if (participant.IdParticipant == inscriere.IdParticipant)
                            list.Add(participant);
                    }
                    //list.Add(participantDbRepository.findOne(inscriere.IdParticipant));
                }
            }
            return list;
        }
        public IEnumerable<Proba> findAllProbeInscris(int idParticipant)
        {
            List<Proba> list = new List<Proba>();
            foreach (Inscriere inscriere in inscriereData)
            {
                if (inscriere.IdParticipant == idParticipant)
                {
                    foreach(var proba in probaData)
                    {
                        if (proba.IdProba == inscriere.IdProba)
                            list.Add(proba);
                    }
                    //list.Add(probaDbRepository.findOne(inscriere.IdProba));
                }
            }
            return list;
        }

        private void viewProbeSelected(object sender, EventArgs e)
        {
            try
            {
                string curItem = listViewProbe.SelectedItem.ToString();
                int idProba = curItem[0] - '0';
                listViewParticipanti.Items.Clear();
                foreach (Participant p in findAllInscrisi(idProba))
                {
                    //listViewParticipanti.Items.Add(p.Nume);
                    String lista = "";
                    foreach (Proba proba in findAllProbeInscris(p.IdParticipant))
                    {
                        if (lista != "")
                        {
                            lista += ", ";
                        }
                        lista += proba.Lungime + "m " + proba.Stil + " ";
                    }
                    listViewParticipanti.Items.Add(p.Nume + " | " + p.Varsta + " | Probe: " + lista);
                }
            }
            catch(NullReferenceException exception)
            {

            }
        }

        private void handleRefresh(object sender, MouseEventArgs e)
        {
            //LoadListViewTable();
            loadComponents();
        }

        private void handleAdd(object sender, MouseEventArgs e)
        {
            string nume = textBoxNume.Text;
            int varsta = Int32.Parse(textBoxVarsta.Text);
            // _service.addParticipant(nume, varsta);
            for (int i = 0; i < checkedListBoxProbe.Items.Count; i++)
            {
                if (checkedListBoxProbe.GetItemChecked(i))
                {
                    ctrl.participantInscris(nume, varsta, i + 1);
                }
            }
        }

        private void handleLogin(object sender, MouseEventArgs e)
        {
            string username = textUsername.Text;
            string password = textPassword.Text;
            //if (server.validateLogin(username, password))
            //{
                textPassword.Clear();
                textUsername.Clear();
                loginPane.Hide();
                mainPane.Show();
                ctrl.login(username, password);

            probaData = ctrl.getProbe();
            loadComponents();
            organizatoriData = ctrl.getLoggedFriends();
            participantData = ctrl.getParticipanti();
            inscriereData = ctrl.getInscrieri();

            //foreach (var elem in probaData)
            //{
            //    listViewProbe.Items.Add(elem);
            //}
            //}
        }
        public void loadComponents()
        {
            listViewProbe.Items.Clear();
            listViewParticipanti.Items.Clear();
            checkedListBoxProbe.Items.Clear();

            foreach (var elem in probaData)
            {
                listViewProbe.Items.Add(elem);

                var row = elem.Lungime.ToString() + " | " + elem.Stil;
                checkedListBoxProbe.Items.Add(row);

            }
        }

        private void handleLogout(object sender, MouseEventArgs e)
        {
            mainPane.Hide();
            loginPane.Show();
        }
    }
}
