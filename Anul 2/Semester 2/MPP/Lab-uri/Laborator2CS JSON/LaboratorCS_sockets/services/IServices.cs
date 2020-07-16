using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using swim.model;
namespace swim.services
{
    public interface IServices
    
    {
        void login(String username,String password, IObserver client);

        void addInscriere(string nume, int varsta, int idProba);

        //IEnumerable<Proba> getProbe();

        Organizator[] getLoggedFriends(Organizator user);

        List<String> getProbe(Organizator user);

        List<String> getParticipanti(Organizator user);

        List<String> getInscrieri(Organizator user);

    }
}
