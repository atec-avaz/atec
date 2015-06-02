using MyChess;
using MyChess.Sokoban;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChessClient
{
    class Program
    {
        static void Main(string[] args)
        {
            //JogoGalo temp = new JogoGalo();

            //if (temp is IBoard)
            //{
            //    IBoard b = (IBoard)temp; 
            //    Console.WriteLine(b.print());
            //}

            //Console.ReadKey();
            Sokoban sok = new Sokoban(8, 8);
            sok.generateRandom();
            Console.WriteLine(sok.print());


            while (sok.GameIsRunning) { 
                ConsoleKeyInfo key = Console.ReadKey();
                MoveType returnMove = sok.placeMove(key);
                switch (returnMove)
                {
                    case MoveType.JogadaOK:
                        Console.WriteLine("Jogada válida!");
                        break;
                    case MoveType.JogadaNOK:
                        Console.WriteLine("Jogada inválida!");
                        break;
                    case MoveType.Won:
                        Console.WriteLine("Ganhou!");
                        break;
                    case MoveType.Loose:
                        Console.WriteLine("Perdeu!");
                        break;
                    case MoveType.InvalidBoard:
                        Console.WriteLine("Tabuleiro Inválido!");
                        break;                    
                }

                Console.WriteLine(sok.print());
            }

            Console.ReadKey();


        }
    }
}
