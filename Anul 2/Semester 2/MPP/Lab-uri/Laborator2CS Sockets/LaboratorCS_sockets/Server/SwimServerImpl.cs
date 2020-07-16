using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using swim.model;
using swim.persistence;
using swim.services;
using System;
namespace swim.server
{
    public class SwimServerImpl: IServices
    {
        private IRepository<int, Participant> participantDbRepository;
        private IRepository<int, Proba> probaDbRepository;
        private IRepository<int, Inscriere> inscriereDbRepository;
        private IRepository<int, Organizator> organizatorDbRepository;
        private readonly IDictionary <int, IObserver> loggedClients;



        public SwimServerImpl(IRepository<int,Participant> participant, IRepository<int, Proba> proba, IRepository<int, Inscriere> inscriere, IRepository<int, Organizator> organizator) {
            participantDbRepository = participant;
            probaDbRepository = proba;
            inscriereDbRepository = inscriere;
            organizatorDbRepository = organizator;

            loggedClients=new Dictionary<int, IObserver>();
        }

        public  void login(Organizator user, IObserver client)  {
            foreach(var organizator in organizatorDbRepository.findAll())
            {
                if( organizator.Username.Equals(user.Username) && organizator.Password.Equals(user.Password))
                {
                    user.IdOrganizator = organizator.IdOrganizator;
                }
            }
            Organizator userOk=organizatorDbRepository.findOne(user.IdOrganizator);
            if (userOk!=null){
                if(loggedClients.ContainsKey(user.IdOrganizator))
                    throw new ChatException("User already logged in.");
                loggedClients[user.IdOrganizator]= client;
            }else
                throw new ChatException("Authentication failed.");
        }

        public void addInscriere(string nume, int varsta, int idProba){
            Console.WriteLine("logged friends "+loggedClients.Count);
            if (findParticipant(nume, varsta) == null)
            {
                try
                {
                    Participant p = new Participant(getAllParticipant().Count() + 1, nume, varsta);
                    participantDbRepository.save(p);
                }
                catch(Exception exception) { }
            }
            int idParticipant = findParticipant(nume, varsta).IdParticipant;
            Inscriere inscriere = new Inscriere(getAllInscriere().Count() + 1, idParticipant, idProba);
            if (findInscriere(idParticipant, idProba) == null)
            {
                inscriereDbRepository.save(inscriere);
                foreach(Proba proba in probaDbRepository.findAll())
                {
                    if (proba.IdProba == idProba)
                    {
                        probaDbRepository.update(idProba, new Proba(idProba, proba.Lungime, proba.Stil, proba.NrParticipanti + 1));
                    }
                }
                foreach (KeyValuePair<int, IObserver> client in loggedClients)
                {
                    IObserver clientObserver = client.Value;
                    //Task.Run(() => clientObserver.participantInscris(nume, varsta, idProba));
                    Task.Run(() => clientObserver.inscriereEfectuata(inscriere,nume,varsta));

                }
            }
        }
        private Participant findParticipant(string nume, int varsta)
        {
            foreach(Participant p in participantDbRepository.findAll())
            {
                if (p.Nume.Equals(nume) && p.Varsta == varsta)
                    return p;
            }
            return null;
        }
        private Inscriere findInscriere(int idParticipant, int idProba)
        {
            foreach (Inscriere i in inscriereDbRepository.findAll())
            {
                if (i.IdParticipant==idParticipant && i.IdProba==idProba)
                    return i;
            }
            return null;
        }
        public IEnumerable<Proba> getAllProba()
        {
            return probaDbRepository.findAll();
        }
        public IEnumerable<Participant> getAllParticipant()
        {
            return participantDbRepository.findAll();
        }
        public IEnumerable<Inscriere> getAllInscriere()
        {
            return inscriereDbRepository.findAll();
        }
        public IEnumerable<Organizator> getAllOrganizator()
        {
            return organizatorDbRepository.findAll();
        }

        public bool validateLogin(string username, string password)
        {
            foreach (Organizator organizator in organizatorDbRepository.findAll())
            {
                if (organizator.Username.Equals(username) && organizator.Password.Equals(password))
                    return true;
            }
            return false;
        }

        public Organizator[] getLoggedFriends(Organizator user)
        {
            //IEnumerable<Organizator> friends = organizatorDbRepository.getFriendsOf(user);
            IList<Organizator> result = new List<Organizator>();
            //Console.WriteLine("Logged friends for: " + user.Id);
            foreach (Organizator friend in organizatorDbRepository.findAll())
            {
                result.Add(friend);
            }
            Console.WriteLine("Size " + result.Count);
            return result.ToArray();
        }

        public Proba[] getProbe(Organizator user)
        {
            IList<Proba> result = new List<Proba>();
            foreach (Proba friend in probaDbRepository.findAll())
            {
                result.Add(friend);
            }
            Console.WriteLine("Size " + result.Count);
            return result.ToArray();
        }

        public Participant[] getParticipanti(Organizator user)
        {
            IList<Participant> result = new List<Participant>();
            foreach (Participant friend in participantDbRepository.findAll())
            {
                result.Add(friend);
            }
            Console.WriteLine("Size " + result.Count);
            return result.ToArray();
        }

        public Inscriere[] getInscrieri(Organizator user)
        {
            IList<Inscriere> result = new List<Inscriere>();
            foreach (Inscriere friend in inscriereDbRepository.findAll())
            {
                result.Add(friend);
            }
            Console.WriteLine("Size " + result.Count);
            return result.ToArray();
        }

    }
}
