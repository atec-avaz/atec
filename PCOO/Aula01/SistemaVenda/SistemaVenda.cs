using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SistemaVenda
{
    public class SistemaVenda
    {
        public static double efectuarVenda(ArrayList produtos, Cliente cliente)
        {
            double valorAPagar = 0;

            foreach (Object obj in produtos)
            {
                if ( !(obj is Produto) )
                    throw new InvalidOperationException("Lista de produtos inválida");
            }

            foreach (Produto produto in produtos)
            {
                double desconto = produto.getDesconto();
                double descontoAdicional = produto.apresentarCartao(cliente.CartaoCliente);
                desconto = Math.Min(descontoAdicional + desconto, .75);
                double parcial = produto.Preco - (produto.Preco * desconto);
                
                valorAPagar += parcial;
            }
            // aplicar desconto cliente
            valorAPagar = valorAPagar - (valorAPagar * cliente.getDesconto());

            return valorAPagar;
        }
                
    }
}
