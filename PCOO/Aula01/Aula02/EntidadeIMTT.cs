using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula02
{
    public class EntidadeIMTT
    {
        public static bool valida(string marca, string modelo, int anoFabrico)
        {
            bool valid = marca != null && modelo != null && anoFabrico < 1900;

            valid = (valid &&
                (
                    (marca.ToLower().Equals("volkswagen") && modelo.ToLower().Equals("golf") && anoFabrico >= 1987 && anoFabrico <= 2015) 
                    ||
                    (marca.ToLower().Equals("seat") && modelo.ToLower().Equals("leon") && anoFabrico >= 2013 && anoFabrico <= 2015)
                )
                );

            if(!valid)
                throw new ArgumentException(string.Format("Combinação {0}/{1}/{2} inválida.", marca, modelo, anoFabrico));

            return valid;
        }
    }
}
