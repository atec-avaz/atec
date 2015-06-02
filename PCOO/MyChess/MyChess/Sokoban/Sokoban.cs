using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public enum MoveType { JogadaOK, JogadaNOK, Won, InvalidBoard, Loose}
    public class Sokoban : Board
    {
        private bool gameEnd = false;
        
        public Sokoban(int sizeLine, int sizeColumn) : base(sizeLine, sizeColumn)
        {
            gameEnd = false;
        }

        protected override void initialize()
        {
            generateRandom();
        }

        public bool GameIsRunning { get { return !gameEnd; } }

        private Cell findHero()
        {
            for (int i = 0; i < sizeLine; i++)
            {
                for (int y = 0; y < sizeColumn; y++)
                {
                    if (board[i, y] is Hero)
                        return getCell(i, y);
                }
            }
            return null;
        }
        
        public void generateRandom()
        {
            board = new Cell[sizeLine, sizeColumn];
            for (int i = 0; i < sizeLine; i++)
            {
                for (int y = 0; y < sizeColumn; y++)
                {
                    Cell currentCell = null;

                    if (i == 1 && y == 1)
                    {
                        currentCell = new Hero(1, 1);                        
                    }
                    else if (i == 2 && y == 3)
                    {
                        currentCell = new Princess(i, y);
                    }
                    else if (i == 3 && ( y == 1 || y == 2 || y == 3 ))
                    {
                        currentCell = new Wall(i, y);
                    }
                    else if (i == sizeLine-1 && y == sizeColumn-1)
                    {
                        currentCell = new Exit(i, y);
                    }                    
                    else
                        currentCell= new Cell(i, y, " ");

                    board[i, y] = currentCell;

                }
            }
        }

        public MoveType placeMove(ConsoleKeyInfo key)
        {
            Cell myHero = findHero();
            if (myHero == null) return MoveType.InvalidBoard;

            MoveType retMove = MoveType.JogadaNOK;
            bool playerCanMove = false;

            Cell neighbour = null;
            Cell aheadNeighbour = null;
            
            int destinationX = myHero.Line;
            int destinationY = myHero.Column;

            int destinationAheadX = myHero.Line;
            int destinationAheadY = myHero.Column;

            if (myHero is IMovable)
            {
                switch (key.Key)
                {
                    case ConsoleKey.W:
                    case ConsoleKey.UpArrow:
                        playerCanMove = ((IMovable)myHero).canMoveUp();                        
                        neighbour = getCell(myHero.Line - 1, myHero.Column);                        
                        aheadNeighbour = getCell(myHero.Line - 2, myHero.Column);
                        destinationX--;
                        destinationAheadX = destinationX;
                        destinationAheadX--;
                        break;
                    case ConsoleKey.A:
                    case ConsoleKey.LeftArrow:
                        playerCanMove = ((IMovable)myHero).canMoveLeft();
                        neighbour = getCell(myHero.Line, myHero.Column-1);
                        aheadNeighbour = getCell(myHero.Line, myHero.Column-2);
                        destinationY--;
                        destinationAheadY = destinationY;
                        destinationAheadY--;
                        break;
                    case ConsoleKey.S:
                    case ConsoleKey.DownArrow:
                        playerCanMove = ((IMovable)myHero).canMoveDown();
                        neighbour = getCell(myHero.Line + 1, myHero.Column);
                        aheadNeighbour = getCell(myHero.Line + 2, myHero.Column);
                        destinationX++;
                        destinationAheadX = destinationX;
                        destinationAheadX++;
                        break;
                    case ConsoleKey.D:
                    case ConsoleKey.RightArrow:
                        playerCanMove = ((IMovable)myHero).canMoveRight();
                        neighbour = getCell(myHero.Line, myHero.Column+1);
                        aheadNeighbour = getCell(myHero.Line, myHero.Column+2);
                        destinationY++;
                        destinationAheadY = destinationY;
                        destinationAheadY++;
                        break;
                }
            }

            if (playerCanMove || neighbour != null)
            {
                // temos uma peça vizinha, dependendo do tipo da peca podemos ter uma jogada valida
                if(neighbour is Wall)
                    retMove = MoveType.JogadaNOK;

                if (neighbour is Princess && aheadNeighbour is Cell && !(aheadNeighbour is Wall))
                {
                    retMove = MoveType.JogadaOK;
                }

                if (neighbour is Princess && aheadNeighbour is Wall)
                {
                    retMove = MoveType.JogadaNOK;
                }
                
                if (neighbour is Princess && aheadNeighbour is Exit)
                    retMove = MoveType.Won;

                if (neighbour is Cell && !(neighbour is Wall || neighbour is Princess || neighbour is Exit))
                    retMove = MoveType.JogadaOK;
                
            }
            else
            {
                // se não temos uma peca vizinha, significa que estamos a tentar sair do tabuleiro
                retMove = MoveType.JogadaNOK;
            }

            if (retMove == MoveType.JogadaOK || retMove == MoveType.Won)
            {
                if (neighbour is IMovable)
                {
                    board[destinationX, destinationY] = new Cell(destinationX, destinationX, " ");
                    ((IMovable)neighbour).moveTo(destinationAheadX, destinationAheadX);
                    board[destinationAheadX, destinationAheadY] = neighbour;
                }


                board[myHero.Line, myHero.Column] = new Cell(myHero.Line, myHero.Column, " ");
                ((IMovable)myHero).moveTo(destinationX, destinationY);
                board[destinationX, destinationY] = myHero;

                
            }

            gameEnd = retMove == MoveType.Won;
            return retMove;
        }

    }
}
