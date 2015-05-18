using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SistemaVenda;
using System.Collections;

namespace Aula04
{
    public class Program
    {
        static void Main(string[] args)
        {
            int teste = 1;            
            Cliente cliente = new Cliente(30);
            

            ArrayList produtos = new ArrayList();
            try
            {
                cliente.CartaoCliente = "12345";
                Console.WriteLine(string.Format("Teste {0}", teste++));

                produtos.Add(new ProdutoA("12345", "produto A", "marca A", 100)); // 100
                produtos.Add(new ProdutoB("12345", "produto A", "marca A", 200)); // 150
                produtos.Add(new ProdutoC("12345", "produto A", "marca A", 300)); // 150

                // 400
                // 30% * 400 = 120
                // 280

                double valorAPagar = SistemaVenda.SistemaVenda.efectuarVenda(produtos, cliente);
                Console.WriteLine(valorAPagar);
                if (valorAPagar != 280) Console.WriteLine("Deveria ser 280 !!!");
            }
            catch (Exception exc) { Console.Error.WriteLine(exc.Message); }
            
            cliente = new Cliente(30);

            try
            {
                Console.WriteLine(string.Format("Teste {0}", teste++));
                cliente = new Cliente(100);
                double valorAPagar = SistemaVenda.SistemaVenda.efectuarVenda(produtos, cliente);
                Console.WriteLine(valorAPagar);
                if (valorAPagar != 0) Console.WriteLine("Deveria ser 0 !!!");
            }
            catch (Exception exc) { Console.Error.WriteLine(exc.Message); }

            try
            {
                Console.WriteLine(string.Format("Teste {0}", teste++));
                produtos.Clear();
                produtos.Add(new ProdutoA("12345", "produto A", "marca A", 0));
                produtos.Add(new ProdutoB("12345", "produto A", "marca A", 0));
                produtos.Add(new ProdutoC("12345", "produto A", "marca A", 0));

                double valorAPagar = SistemaVenda.SistemaVenda.efectuarVenda(produtos, cliente);
                Console.WriteLine(valorAPagar);
                if (valorAPagar != 0) Console.WriteLine("Deveria ser 0 !!!");
            }
            catch (Exception exc) { Console.Error.WriteLine(exc.Message); }

            try
            {
                Console.WriteLine(string.Format("Teste {0}", teste++));
                cliente = new Cliente(110);

                produtos.Clear();
                produtos.Add("sdfghjk");

                double valorAPagar = SistemaVenda.SistemaVenda.efectuarVenda(produtos, cliente);
                Console.WriteLine(valorAPagar);
                if (valorAPagar != 0) Console.WriteLine("Deveria ser 0 !!!");
            }
            catch (Exception exc) { Console.Error.WriteLine(exc.Message); }

            try
            {
                Console.WriteLine(string.Format("Teste {0}", teste++));
                produtos.Clear();
                produtos.Add("");

                double valorAPagar = SistemaVenda.SistemaVenda.efectuarVenda(produtos, cliente);
                Console.WriteLine(valorAPagar);
                if (valorAPagar != 0) Console.WriteLine("Deveria ser 0 !!!");
            }
            catch (Exception exc) { Console.Error.WriteLine(exc.Message); }
            
            Console.ReadKey();

        }
    }
}
