using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula1
{
    class Aula1
    {
        public static void Main(String[] args)
        {
            double valor = 0;
            bool erro = true;

            do
            {
                try
                {
                    
                    String readLine = Console.ReadLine();
                    valor = double.Parse(readLine);
                    erro = false;
                }
                catch (FormatException exc)
                {
                    erro = true;
                }
            } while (erro);

            Console.ReadKey();

            
        }
    }

    // enums
    

    // read int
    // read string
    // read double
    // detect key

}
