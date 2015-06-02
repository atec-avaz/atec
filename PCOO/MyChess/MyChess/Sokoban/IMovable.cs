using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess.Sokoban
{
    public interface IMovable
    {
        bool canMoveUp();
        bool canMoveDown();
        bool canMoveLeft();
        bool canMoveRight();

        void moveTo(int newX, int newY);
    }
}
