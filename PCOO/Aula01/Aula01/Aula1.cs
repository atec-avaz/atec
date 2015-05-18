using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula01
{
    class Aula1
    {
        static void Main(string[] args)
        {

            int xpto = 7850;
            float zx = 56;
            uint tyui = 7878u;

            Console.Write("xpto=" + xpto + "  zx = " + zx + "  tyui = " + tyui);
            Console.WriteLine();
            Console.WriteLine("Élou");

            bool valor_ok = false;
            do
            {
                try
                {
                    string leitura = Console.ReadLine();

                    xpto = Int32.Parse(leitura);
                    valor_ok = true;
                }
                catch (Exception)
                {
                    // 
                }
            } while (!valor_ok);

            // xpto
            //Console.WriteLine("xpto lido pelo user =" + xpto);

            //if (args.Length > 0)
            //{
            //    int xyz = Int32.Parse(args[0]);
            //    string nome = args[1];


            //    Console.WriteLine("xyz =" + xyz);
            //    Console.WriteLine("nome =" + nome);
            //}

            //Console.ReadKey();


            //for (int i = 0; i < 10; i++)
            //{
            //    Console.Write("asd");
            //}


            //Console.ReadKey();


            //while(2!=3){
            //    Console.Write("asd");
            //    if (Math.PI < 4)
            //        break;
            //}

            //Console.ReadKey();

            foreach (string s in args)
            {
                foreach (char c in s)
                {
                    Console.WriteLine(c);
                }
                Console.WriteLine();
            }
            Console.ReadKey();

        }
    }
}
