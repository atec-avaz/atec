using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public class Princess : Cell, IMovable
    {
        public const string C_PRINCESS_LABEL = "P";

        public Princess(int line, int column) :
            base(line, column, C_PRINCESS_LABEL)
        { 
        
        }
        public override string ToString()
        {
            return C_PRINCESS_LABEL;
        }

        public void moveTo(int newX, int newY)
        {
            this.line = newX;
            this.column = newY;
        }

        public bool canMoveUp()
        {
            return true;
        }

        public bool canMoveDown()
        {
            return true;
        }

        public bool canMoveLeft()
        {
            return true;
        }

        public bool canMoveRight()
        {
            return true;
        }
    }
}
