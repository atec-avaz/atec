using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula02
{
    class Program
    {
        static void Main(string[] args)
        {
            //Pessoa p = new Pessoa(new DateTime(1984, 6, 26));
            //Console.WriteLine(p.getIdade());
            //Console.WriteLine(p.getNome());
            
            //try { 
            //    p.setNome(null);
            //}
            //catch (ArgumentNullException exc)
            //{
            //    Console.WriteLine("ERRO=>" + exc.Message);
            //}
            
            //Console.WriteLine(p.getNome());
            //Console.WriteLine(p.getAnoNascimento());            
            //Console.WriteLine(p.getIdade());

            try
            {
                if(EntidadeIMTT.valida("renault", "corsa", 2015))
                    Console.WriteLine("Combinação válida");

                if (EntidadeIMTT.valida("volkswagen", "golf", 2015))
                    Console.WriteLine("Combinação válida");
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc.Message);
            }

            Volkswagen v = new Volkswagen("golf", 2013);
            Console.WriteLine(v.ToString());


            Console.ReadKey();
        }

        private static int lerInt()
        {
            bool valorOK = false;
            int valorLido = 0;
            do{
                try { 
                    valorLido = Int32.Parse(Console.ReadLine());
                    valorOK = true;
                }
                catch (Exception)
                {
                    Console.WriteLine("Valor inválido detectado, introduza apenas um número inteiro!");
                }
            }while(!valorOK);

            return valorLido;
        }
    }
}
