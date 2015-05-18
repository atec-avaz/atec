using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SistemaVenda
{
    public abstract class Produto: IDesconto
    {
        private string codBarras;
        private string descricao;
        private string marca;
        private double preco;

        public Produto(string codBarras, string descricao, string marca, double preco)
        {
            this.codBarras = codBarras;
            this.descricao = descricao;
            this.marca = marca;
            this.preco = preco;
        }

        public string CodBarras { get { return codBarras; } }
        public string Descricao { get { return descricao; } }
        public string Marca { get { return marca; } }
        public double Preco { get { return preco; } }


        public virtual double getDesconto()
        {
            return 0.0;
        }

        public double apresentarCartao(string codCartao)
        {
            if(codCartao.Equals("12345"))
                return 0.25;

            return 0;
        }
    }
}
