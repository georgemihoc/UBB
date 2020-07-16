using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using swim.model;

namespace swim.services
{
    public interface IObserver
    {
        void participantInscris(string nume, int varsta, int idProba);

        void loggedIn(Organizator user);

        void refresh(Inscriere inscriere);

        void inscriereEfectuata(Inscriere inscriere,string nume, int varsta);

    }
}
