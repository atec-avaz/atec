using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public class Exit: Cell
    {
        public const string C_EXIT_LABEL = "X";

        public Exit(int line, int column) :
            base(line, column, C_EXIT_LABEL)
        { 
        
        }
        public override string ToString()
        {
            return C_EXIT_LABEL;
        }
    }
}
