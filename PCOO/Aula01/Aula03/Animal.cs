using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula03
{
    public abstract class Animal
    {
        public virtual string talk(){
            return "Talk Animal";
        }
    }

    public class Cat : Animal
    {
        public override string talk()
        {
            return "Talk Cat";
        }
    }

    public class DumbCat:Cat{
	    public override string talk(){ 
		    return "Talk DumbCat";
	    }
    }

    public class Dog:Animal{
	    public override string talk(){ 
		    return "Talk Dog";
	    }
    }
}
