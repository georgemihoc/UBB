using System;
using System.Collections.Generic;
using swim.model;
using swim.services;

namespace swim.client
{
    

    public class ChatClientCtrl: IObserver
    {
        public event EventHandler<ChatUserEventArgs> updateEvent; //ctrl calls it when it has received an update
        private readonly IServices server;
        private Organizator currentUser;
        public ChatClientCtrl(IServices server)
        {
            this.server = server;
            currentUser = null;
        }

        public void login(String username, String pass)
        {
            //User user=new User(userId,pass);
            //server.login(user,this);
            //Console.WriteLine("Login succeeded ....");
            //currentUser = user;
            //Console.WriteLine("Current user {0}", user);
            currentUser = new Organizator(0,username,pass);

            server.login(new Organizator(0, username, pass), this);
        }
        //public void messageReceived(Message message)
        //{
        //    String mess = "[" + message.Sender.Id + "]: " + message.Text;
        //    ChatUserEventArgs userArgs=new ChatUserEventArgs(ChatUserEvent.NewMessage,mess);
        //    Console.WriteLine("Message received");
        //    OnUserEvent(userArgs);
        //}

        protected virtual void OnUserEvent(ChatUserEventArgs e)
        {
            if (updateEvent == null) return;
            updateEvent(this, e);
            Console.WriteLine("Update Event called");
        }

        public void participantInscris(string nume,int varsta, int idProba)
        {
            server.addInscriere(nume, varsta, idProba);
            ////display the sent message on the user window
            //String mess = "[" + currentUser.Id + "-->"+id+"]: " + txt;
            //ChatUserEventArgs userArgs = new ChatUserEventArgs(ChatUserEvent.NewMessage, mess);
            //OnUserEvent(userArgs);
            ////sends the message to the server
            //User receiver=new User(id);
            //Message message=new Message(currentUser,receiver, txt);
            //server.sendMessage(message);
        }

        public void loggedIn(Organizator user)
        {
            throw new NotImplementedException();
        }

        public void refresh(Inscriere inscriere)
        {
            //String mess = "[" + message.Sender.Id + "]: " + message.Text;
            ChatUserEventArgs userArgs = new ChatUserEventArgs(ChatUserEvent.ParticipantAdaugat, inscriere);
            Console.WriteLine("Interfata reloadata");
            OnUserEvent(userArgs);
        }
        //public IEnumerable<Proba> getProbe()
        //{
        //   // return server.getProbe();
        //}
        public IList<string> getLoggedFriends()
        {
            IList<string> loggedFriends = new List<string>();

            Organizator[] friends = server.getLoggedFriends(currentUser);
            foreach (var user in friends)
            {
                loggedFriends.Add(user.Username);
            }
            return loggedFriends;
        }

        public IList<Proba> getProbe()
        {

            IList<Proba> listaProbe = new List<Proba>();

            Proba[] probe = server.getProbe(currentUser);
            foreach (var proba in probe)
            {
                listaProbe.Add(proba);
            }
            return listaProbe;
        }
        public IList<Participant> getParticipanti()
        {

            IList<Participant> listaParticipanti = new List<Participant>();

            Participant[] participanti = server.getParticipanti(currentUser);
            foreach (var participant in participanti)
            {
                listaParticipanti.Add(participant);
            }
            return listaParticipanti;
        }
        public IList<Inscriere> getInscrieri()
        {

            IList<Inscriere> listaInscriere = new List<Inscriere>();

            Inscriere[] inscrieri = server.getInscrieri(currentUser);
            foreach (var inscriere in inscrieri)
            {
                listaInscriere.Add(inscriere);
            }
            return listaInscriere;
        }

        public void inscriereEfectuata(Inscriere inscriere, string nume, int varsta)
        {
            throw new NotImplementedException();
        }
    }
}
