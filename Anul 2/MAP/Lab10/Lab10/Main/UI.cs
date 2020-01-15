using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Globalization;
using System.Linq;
using Lab10.Service;

namespace Lab10
{
    public class UI
    {
        private ElevService elevService;
        private EchipaService echipaService;
        private JucatorService jucatorService;
        private MeciService meciService;
        private JucatorActivService jucatorActivService;
        private AService service;
        
        public UI(ElevService elevService, EchipaService echipaService, JucatorService jucatorService, MeciService meciService, JucatorActivService jucatorActivService, AService service)
        {
            this.elevService = elevService;
            this.echipaService = echipaService;
            this.jucatorService = jucatorService;
            this.meciService = meciService;
            this.jucatorActivService = jucatorActivService;
            this.service = service;
        }

        public static void meniu()
        {
            Console.WriteLine("1.Sa se afiseze toti jucatorii unei echipe dată");
            Console.WriteLine("2.Sa se afiseze toti jucatorii activi ai unei echipe de la un anumit meci");
            Console.WriteLine("3.Sa se afiseze toate meciurile dintr-o anumita perioada calendaristica");
            Console.WriteLine("4.Sa se determine si sa se afiseze scorul de la un anumit meci");
            Console.WriteLine("5.Add elev");
            Console.WriteLine("6.Add echipa");
            Console.WriteLine("7.Add meci");
            Console.WriteLine("0.EXIT");
        }

        public int Citire()
        {
            int cmd;
            try
            {
                cmd = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                return -1;
            }

            return cmd;
        }
        
        public void TotiJucatoriiUneiEchipe()
        {
            Console.Write("Introduceti echipa: ");
            string echipa = Console.ReadLine();
            Console.WriteLine();
            List<Jucator> jucatori = service.TotiJucatoriiUneiEchipe(echipa);
            
            if(jucatori.Count==0)
                Console.WriteLine("Echipa nu exista sau nu contine jucatori");
            else
            {
                jucatori
                    .Select(a => a.Nume)
                    .ToList()
                    .ForEach(Console.WriteLine);
                Console.WriteLine();
            }
        }
        
        public void TotiJucatoriiMeci()
        {
            Console.Write("Introduceti meciul: ");
            string meci = Console.ReadLine ();
            Console.Write("Introduceti echipa: ");
            string numeEchipa = Console.ReadLine ();
            Console.WriteLine();
            
            List<JucatorActiv> jucatoriActivi = service.TotiJucatoriiMeci(meci,numeEchipa);
            if(jucatoriActivi.Count==0)
                Console.WriteLine("Nu exista jucatori");
            else
            {
                jucatoriActivi
                    .ForEach(Console.WriteLine);
                Console.WriteLine();
            }
        }
        
        private void ToateMeciurilePerioada()
        {
            Console.Write("Introduceti inceputul perioadei: ");
            DateTime start = DateTime.Parse(Console.ReadLine());
            Console.Write("Introduceti sfarsitul perioadei: ");
            DateTime finish = DateTime.Parse(Console.ReadLine());
            List<Meci> meciuri = service.ToateMeciurile(start, finish);
            Console.WriteLine();
            if(meciuri.Count==0)
                Console.WriteLine("Nu exista meciuri in perioada selectata");
            else
            {
                meciuri
                    .ForEach(Console.WriteLine);
                Console.WriteLine();
            }
        }
        
        private void ScorulAnumitMeci()
        {
            Console.Write("Introduceti meciul: ");
            string meci = Console.ReadLine ();
            service.ScorMeci(meci).ForEach(Console.WriteLine);
        }
        
        private void AddElev()
        {
            Console.Write("Introduceti numele elevului: ");
            string nume =Console.ReadLine();
            Console.Write("Introduceti scoala: ");
            string scoala =Console.ReadLine();
            try
            {
                elevService.AddElev(nume, scoala);

            }
            catch (ValidationException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        private void AddEchipa()
        {
            Console.Write("Introduceti numele echipei: ");
            string nume =Console.ReadLine();
            
            if(nume.StartsWith('e'))
                echipaService.AddEchipa(nume);
            else
            {
                Console.WriteLine("Echipa invalida");
            }
        }
        
        private void AddMeci()
        {
            try
            {
                Console.Write("Introduceti prima echipa : ");
                string echipa1 = Console.ReadLine();
                Console.Write("Introduceti a doua echipa: ");
                string echipa2 = Console.ReadLine();
                Console.Write("Introduceti data meciului : ");
                DateTime date = DateTime.Parse(Console.ReadLine());
                meciService.AddMeci(echipa1, echipa2, date);
            }
            catch (Exception ignore)
            {
                Console.WriteLine("Meci invalid");
            }
        }

        public void Run()
        {
            while (true)
            {
                meniu();
                int cmd = Citire();
                switch (cmd)
                { 
                    case 1: TotiJucatoriiUneiEchipe();
                        break;
                    case 2: TotiJucatoriiMeci();
                        break;
                    case 3: ToateMeciurilePerioada();
                        break;
                    case 4: ScorulAnumitMeci();
                        break;
                    case 5: AddElev();
                        break;
                    case 6: AddEchipa();
                        break;
                    case 7: AddMeci();
                        break;
                    case 0:
                        Console.WriteLine("EXIT");
                        return;
                    default: Console.WriteLine("Comanda introdusa nu exista");
                        break;
                }
            }
        }
    }
}