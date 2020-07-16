using System;

namespace ConsoleApp1
{
    public class Tractor
    {
        private String culoare;
        private String marca;
        private int anProductie;

        public string Culoare
        {
            get => culoare;
            set => culoare = value;
        }

        public string Marca
        {
            get { return marca; }
            set { marca = value;}
        }

        public int AnProductie
        {
            get => anProductie;
            set => anProductie = value;
        }

        public override string ToString()
        {
            return culoare+anProductie+marca;
        }
    }
}