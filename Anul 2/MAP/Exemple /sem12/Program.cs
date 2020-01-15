
using Curs12.Repository;
using Curs12.Repository.Validator;
using Curs12.Repository;
using Curs12.Service;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;

namespace Curs12
{
    class Program
    {

        static void Main(string[] args)
        {
            //StreamReader rd = new StreamReader(path);
            //Console.WriteLine(typeof(KnowledgeLevel));
            //KnowledgeLevel level = (KnowledgeLevel)Enum.Parse(typeof(KnowledgeLevel), "Junior");

            List<Angajat> angajati = GetAngajatService().FindAllAngajati();
            List<Sarcina> sarcini = GetSarcinaService().FindAllSarcini();
            List<Pontaj> pontaje = GetPontajService().FindAllPontaje();

            //angajati.ForEach(Console.WriteLine);
            //Console.WriteLine("Sarcini");
            //sarcini.ForEach(Console.WriteLine);

            //Console.WriteLine("Pontaje");

            //pontaje.ForEach(Console.WriteLine);


//            Console.WriteLine("Cei mai harnici");
//
//            GetPontajService().CeiMaiHarnici().Select(kvp => kvp.Key + ": " + kvp.Value.ToString()).ToList().ForEach(Console.WriteLine); 

            //Task2();

            Console.WriteLine("introduceti luna");
            string luna = Console.ReadLine();
            int a = Convert.ToInt32(luna);

            GetPontajService().Salar(a).ForEach(Console.WriteLine);

        }

        private static void Task2()
        {
            List<Angajat> list = GetAngajatService().FindAllAngajati();
            //list.ForEach(Console.WriteLine);
            var newList = list.Where(x => x.Nivel == KnowledgeLevel.Junior);
            //newList.ToList().ForEach(Console.WriteLine);
            //(from angajat in list
            // where angajat.Nivel == KnowledgeLevel.Junior
            // select angajat).ToList().ForEach(Console.WriteLine);


            list.Sort((x, y) =>
            {
                if(x.Nivel == y.Nivel)
                {
                    return -(int)(x.VenitPeOra - y.VenitPeOra);
                }
                return (int)(x.Nivel - y.Nivel);
            });

            list.ForEach(Console.WriteLine);

            //(from angajat in list
            // orderby angajat.Nivel ascending, angajat.VenitPeOra descending
            // select angajat).ToList().ForEach(Console.WriteLine);

            var res=from a in list
            group a by a.Nivel into g
            select new { Nivel = g.Key, Media = g.Average(x=>x.VenitPeOra) };

            //res.ToList().ForEach(Console.WriteLine);

            list.GroupBy(a => a.Nivel)
                .Select(a => new { Nivel = a.Key, Media = a.Average(x => x.VenitPeOra) })
                .ToList()
                .ForEach(Console.WriteLine);
        }
        
        private static AngajatService GetAngajatService()
        {
            string fileName2 = ConfigurationManager.AppSettings["angajatiFileName"];
            //string fileName = "..\\..\\..\\Data\\angajati.txt";
            IValidator<Angajat> vali = new AngajatValidator();

            IRepository<string, Angajat> repo1 = new AngajatInFileRepository(vali, fileName2);
            AngajatService service = new AngajatService(repo1);
            return service;
        }

        private static SarcinaService GetSarcinaService()
        {
            string fileName2 = ConfigurationManager.AppSettings["sarciniFileName"];
//            Console.WriteLine(fileName2);
            IValidator<Sarcina> vali = new SarcinaValidator();

            IRepository<string, Sarcina> repo1 = new SarcinaInFileRepository(vali, fileName2);
            SarcinaService service = new SarcinaService(repo1);
            return service;
        }

        private static PontajService GetPontajService()
        {
            string fileName2 = ConfigurationManager.AppSettings["pontajeFileName"];
            IValidator<Pontaj> vali = new PontajValidator();

            IRepository<string, Pontaj> repo1 = new PontajInFileRepository(vali, fileName2);
            PontajService service = new PontajService(repo1);
            return service;
        }
    }
}