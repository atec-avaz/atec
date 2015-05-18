using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula02
{
    public class Automovel
    {
        private string cor;
        private string marca;
        private string modelo;
        private int anoFabrico;

        public Automovel(string cor, string marca, string modelo, int anoFabrico)
        {
            this.cor = cor;
            this.marca = marca;
            this.modelo = modelo;
            this.anoFabrico = anoFabrico;
        }

        public override string ToString()
        {
            return string.Format("Automovel: Cor:{0}, Marca:{1}, Modelo:{2}, AnoFabrico:{3}", cor, marca, modelo, anoFabrico);
        }

        public string Cor { get { return cor; } }
        public string Marca { get { return marca; } }
        public string Modelo { get { return modelo; } }
        public int AnoFabrico { get { return anoFabrico; } }
    }
}
