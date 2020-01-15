using System;
using System.Linq;

namespace Seminar11
{
    class Program
    {

        static void Main(string[] args)
        {
//1
//            String text = "ACESTA Este UN Text MARE";
//            var rez = from v in text.Split(' ')
//                where v.ToUpper().Equals(v)
//                select v;
//            //foreach (string cuv in rez)
//            //    Console.WriteLine(cuv);
//            //rez.ToList().ForEach(cuv => Console.WriteLine(cuv));
//            rez.ToList().ForEach(Console.WriteLine);
//            text.Split(' ').Where(v => v.ToUpper().Equals(v)).ToList().ForEach(Console.WriteLine);
//            int[] numbers = {1, 2, 3, 5, 2, 1, 2, 3, 6, 2, 2, 4, 1, 2, 1, 4, 6, 2, 4, 1, 2, 5, 7};
//            //var result = from nr in numbers
//            //             group nr by nr into g
//// select g;
//            //result.ToList().ForEach((nr) => Console.WriteLine(nr.Key + " apare de: " + nr.Count()+ " ori."));
//            numbers.GroupBy(nr => nr).ToList()
//                .ForEach(nr => Console.WriteLine(nr.Key + " apare de: " + nr.Count() + " ori."));
//            numbers.Distinct().Where(nr => nr * nr > 20).Select(nr => new
//            {
//                Numar = nr,
//                Patrat = nr * nr
//            }).ToList().ForEach(nr => Console.WriteLine("Numar: " + nr.Numar + ", Patrat: " + nr.Patrat));
            int[] numere = {1, 4, 16, 7, 2, 88, 14, 3, 0, 35, 24, 88, 88};
            Predicate<int> lessThan15Pred = LessThan15Method;
            numere.Where(x => LessThan15Method(x))
                .Select(x=> x*3)
                .ToList()
                .ForEach(x=> Console.WriteLine(x));
//                .ForEach(Console.WriteLine);

            var result = from n in numere
                where LessThan15Method(n)
                select  n;
            result.ToList().ForEach(x=>Console.WriteLine(x));

            var result2 = from n in numere
                where LessThan15Method(n)
                group n by n
                into g
                select new {Value = g.Key, Count = g.Count()};
//            numere[0] = 1;
            result2.ToList().ForEach(x=>Console.WriteLine(x));
            
            numere.GroupBy(x=>x)
                .Select(g => new{Value = g.Key, Count = g.Count()})
                .ToList()
                .ForEach(Console.WriteLine);

            var result3 = from n in numere
                orderby n descending
                select n;
            result3.ToList().ForEach(Console.WriteLine);

            numere.OrderBy(x => -x).ToList().ForEach(Console.WriteLine);
            
            var rez = numere.ToList();
                rez.Sort((x,y) => y-x);
            rez.ForEach(Console.WriteLine);

        }
        
        static bool LessThan15Method(int nr)
        {
            return nr < 15;
        }
    }
}