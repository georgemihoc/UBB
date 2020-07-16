using System;
using System.Collections.Generic;
using System.Linq;

namespace ScrisCSharp
{
    class Shape
    {
        public virtual void Draw()
        {
            Console.WriteLine("Shape");
        }
    }
    
    class  Circle : Shape
    {
        public new void Draw()
        {
            Console.WriteLine("Circle ");
        }
    }
   
    class Program
    {
        static void DrawShapes<T>(List<T> shapes)
        where T : Shape
        {
            shapes.ForEach(x=> x.Draw());
        }
        public static void Main()
        {
            List<Shape> c = new Shape[2] 
                {new Circle(), new Shape()}.ToList();
            DrawShapes(c);
            // Shape s1 = new Shape();
            // s1.Draw();
            // Circle c1 = new Circle();
            // c1.Draw();
            Shape s2 = new Circle();
            s2.Draw();
            
            // List<String> names = new List<String> {"AQ","ZW"};
            // var result = from v in names select v;
            // var l = result.ToList();
            // names.Add("CK");
            // result.ToList().ForEach(Console.WriteLine);
            // // String[] strings = {"Hello", "world"} ;
            // // String[] obj = strings;
            // // Console.WriteLine(obj);


            // List<String> names = new List<String> {"XX", "BB"};
            // var result = from v in names select v;
            // names.Add("XB");
            // result.ToList().ForEach(Console.Write);
        }
    }
}