using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess
{
    public interface IBoard
    {
        Cell getCell(int line, int column);
        string print();
    }
}
