using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess
{
    public class Board : IBoard
    {
        protected int sizeLine;
        protected int sizeColumn;
        protected Cell[,] board = null;

        public Board(int sizeLine, int sizeColumn)
        {
            this.sizeLine = sizeLine;
            this.sizeColumn = sizeColumn;
            initialize();
        }

        protected virtual void initialize()
        {
            board = new Cell[sizeLine, sizeColumn];
            for (int currentLine = 0; currentLine < sizeLine; currentLine++)
                for (int currentColumn = 0; currentColumn < sizeColumn; currentColumn++)
                    board[currentLine, currentColumn] = new Cell(currentLine, currentColumn, "X");
        }

        public Cell getCell(int line, int column)
        {
            if (line < 0 || column < 0 || line >= sizeLine || column >= sizeColumn) return null;

            return board[line, column];
        }

        public string print()
        {
            StringBuilder str = new StringBuilder();
            str.AppendLine("MyBoard");

            str.Append("=");
            for (int currentLine = 0; currentLine < sizeLine; currentLine++)
                str.Append("==");

            str.AppendLine();
            
            for (int currentLine = 0; currentLine < sizeLine; currentLine++)
            {
                for (int currentColumn = 0; currentColumn < sizeColumn; currentColumn++)
                {
                    Cell currentCell = getCell(currentLine, currentColumn);
                    string linhaFormat = string.Format("{0}{1}{2}",
                        (currentColumn == 0) ?"|":"",
                            ((currentCell != null) ? currentCell.Label : " "),
                            ((currentColumn == sizeColumn - 1) ? "|" : "|")
                            );
                    str.Append(linhaFormat);
                }
                
                str.AppendLine();

                if (currentLine >= 0)
                {
                    str.Append("=");
                    for (int currentLineAux = 0; currentLineAux < sizeLine; currentLineAux++)
                        str.Append("==");
                }

                str.AppendLine();
            }

            
            return str.ToString();
        }
    }
}
