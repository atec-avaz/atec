using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula02
{
    public class Volkswagen: Automovel
    {
        public Volkswagen(string modelo, int anoFabrico) : 
            base("Unknown", "Volkswagen", modelo, anoFabrico)
        {

        }

        public override string ToString()
        {
            string retStr = base.ToString();
            retStr = "VW " + retStr;
            return retStr;
        }
    }
}
