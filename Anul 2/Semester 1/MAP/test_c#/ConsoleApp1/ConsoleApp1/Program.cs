using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Tractor t = new Tractor();
            t.Culoare = "negru";
            t.AnProductie = 3000;
            t.Marca = "boss";

            Tractor t1 = new Tractor()
            {
                Culoare = "albastru",
                AnProductie = 2000,
                Marca = "sefu"
            };
            
            Console.WriteLine(t.Culoare);
            Console.WriteLine(t1);
        }
    }
}