using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using swim.model;
namespace swim.services
{
    public interface IServices
    
    {
        void login(Organizator user, IObserver client);

        void addInscriere(string nume, int varsta, int idProba);

        //IEnumerable<Proba> getProbe();

        Organizator[] getLoggedFriends(Organizator user);

        Proba[] getProbe(Organizator user);

        Participant[] getParticipanti(Organizator user);

        Inscriere[] getInscrieri(Organizator user);

    }
}
