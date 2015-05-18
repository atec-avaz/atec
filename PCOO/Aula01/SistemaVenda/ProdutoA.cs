using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SistemaVenda
{
    public class ProdutoA:Produto
    {
        public ProdutoA(string codBarras, string descricao, string marca, double preco): 
            base(codBarras, descricao, marca, preco)
        {
            
        }
    }
}
