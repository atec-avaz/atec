using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula03
{
    public class Curso
    {
        private ArrayList disciplinas;

        public Curso()
        {
            disciplinas = new ArrayList();
        }

        public void adicionarUFCD(string nomeUFCD)
        {
            disciplinas.Add(nomeUFCD);
        }

        public void removerUFCD(string nomeUFCD)
        {
            disciplinas.Remove(nomeUFCD);
        }

        public void testeLINQ()
        {
            var query = from string str in disciplinas
                        where str.Length > 4
                        select str;

            foreach (string s in query)
                Console.WriteLine(s);
        }

        public string consultarUFCD()
        {
            StringBuilder str = new StringBuilder();
            bool first = true;
            foreach (string item in disciplinas)
            {
                if (!first) 
                {
                    str.Append("; ");
                }
                else 
                    first = false;

                str.Append(item);
                
            }
            return str.ToString();
        }
    }
}
