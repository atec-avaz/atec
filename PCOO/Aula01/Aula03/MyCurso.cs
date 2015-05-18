using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula03
{
    public class MyCurso
    {
        private string[] disciplinas;
        private int numDisciplinas = 0;
                
        public void adicionarUFCD(string ufcd)
        {
            if (disciplinas == null) { 
                disciplinas = new string[1];
            }
            else
            {
                if (disciplinas.Length < numDisciplinas + 1)
                {
                    // estamos sem espaço ...
                    string[] temp = new string[numDisciplinas + 1];
                    Array.Copy(disciplinas, temp, numDisciplinas);

                    disciplinas = temp;
                }
            }
            
            if (disciplinas.Length > numDisciplinas)
                disciplinas[numDisciplinas++] = ufcd;
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
