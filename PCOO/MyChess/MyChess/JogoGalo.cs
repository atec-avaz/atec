using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess
{
    public class JogoGalo : Board
    {

        public JogoGalo() : base(3, 3){}

        protected override void initialize()
        {
            base.board = new Cell[sizeLine, sizeColumn];
            for (int currentLine = 0; currentLine < 1; currentLine++)
                for (int currentColumn = 0; currentColumn < sizeColumn; currentColumn++)
                    base.board[currentLine, currentColumn] = new Cell(currentLine, currentColumn, "O");
        }
    }
}
