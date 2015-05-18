using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SistemaVenda
{
    public class ProdutoB: Produto
    {
        public ProdutoB(string codBarras, string descricao, string marca, double preco): 
            base(codBarras, descricao, marca, preco)
        {
            
        }

        public override double getDesconto()
        {
            return .25;
        }
    }
}
