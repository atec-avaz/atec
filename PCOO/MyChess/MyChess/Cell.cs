using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyChess
{
    public class Cell
    {
        protected int line;

        protected int column;

        private string label;

        public Cell(int line, int column, string label)
        {
            this.line = line;
            this.column = column;
            this.label = label;
        }

        public int Line { get { return line; } }        
        public int Column { get { return column; } }
        public String Label { get { return label; } }

        public override string ToString()
        {
            return label;
        }
    }
}
