using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public class Hero : Cell, IMovable
    {
        public const string C_HERO_LABEL = "H";

        public Hero(int line, int column) :
            base(line, column, C_HERO_LABEL)
        { 
        
        }
        public override string ToString()
        {
            return C_HERO_LABEL;
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

        public void moveTo(int newX, int newY)
        {
            this.line = newX;
            this.column = newY;
        }
    }
}
