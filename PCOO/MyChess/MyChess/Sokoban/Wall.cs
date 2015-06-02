using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public class Wall:Cell
    {
        public const string C_WALL_LABEL = "#";

        public Wall(int line, int column) :
            base(line, column, C_WALL_LABEL)
        { 
        
        }
        public override string ToString()
        {
            return C_WALL_LABEL;
        }
    }
}
