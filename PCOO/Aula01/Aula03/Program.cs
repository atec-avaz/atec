using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula03
{
    class Program
    {
        static void Main(string[] args)
        {
            Cat cat = new DumbCat();
            Console.WriteLine(cat.talk());


            //MyCurso v = new MyCurso();
            //v.adicionarUFCD("5412");
            //v.adicionarUFCD("5413");
            //v.adicionarUFCD("5415");
            //v.adicionarUFCD("5417");            
            //Console.WriteLine(v.consultarUFCD());


            //Curso c = new Curso();
            //c.adicionarUFCD("5412");
            //c.adicionarUFCD("5413");
            //c.adicionarUFCD("5415");
            //c.adicionarUFCD("5417");
            //c.adicionarUFCD("125417");
            //c.adicionarUFCD("215417");
            //c.adicionarUFCD("315417");

            //c.removerUFCD("5413");

            //Console.WriteLine(c.consultarUFCD());

            //c.testeLINQ();
            
            Console.ReadKey();
        }
    }
}
