using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Channels;
using Curs12.Repository;
using Lab10.Repository;
using Lab10.Repository.Validator;
using Lab10.Service;


namespace Lab10
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName1 = "/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/elevi.txt";
            IValidator<Elev> validator = new ElevValidator();

            IRepository<string, Elev> repo1 = new ElevInFileRepository(validator,fileName1);
            ElevService service1 = new ElevService(repo1);

            string fileName2 = "/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/echipe.txt";
            IRepository<string, Echipa> repo2 = new EchipaInFileRepository(fileName2);
            EchipaService service2 = new EchipaService(repo2);

            string fileName3 = "/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/meciuri.txt";
            IRepository<string, Meci> repo3 = new MeciInFileRepository(fileName3);
            MeciService service3 = new MeciService(repo3);

            string fileName4 = "/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/jucatori.txt";
            IRepository<string, Jucator> repo4 = new JucatorInFileRepository(fileName4);
            JucatorService service4 = new JucatorService(repo4);

            string fileName5 = "/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/jucatoriActivi.txt";
            IRepository<string, JucatorActiv> repo5 = new JucatorActivInFileRepository(fileName5);
            JucatorActivService service5 = new JucatorActivService(repo5);


            AService service = new AService(repo1, repo2, repo4, repo3, repo5);
            UI ui = new UI(service1, service2, service4, service3, service5, service);
            ui.Run();
        }
    }
}