using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SistemaVenda
{
    public class Cliente
    {
        private double desconto = 0;
        private string Nome { get; set; }
        private string Nif { get; set; }
        private string Morada { get; set; }
        private string cartao = "00000";

        public Cliente()
            : this("John Doe", "123456789", "Unknown", 0)
        {

        }

        public Cliente(double desconto) : this("John Doe", "123456789", "Unknown", desconto)
        {

        }

        public Cliente(string nome, string nif, string morada, double desconto)
        {
            this.Nome = nome;
            this.Nif = nif;
            this.Morada = morada;

            if (desconto < 0 || desconto > 100) 
                throw new ArgumentOutOfRangeException("desconto", "O desconto tem que estar compreendido entre 0 e 100%");

            this.desconto = desconto/100;
        }

        public string CartaoCliente
        {
            set { cartao = value; }
            get { return cartao; }
        }

        public double getDesconto()
        {
            return desconto;
        }
        
    }
}
