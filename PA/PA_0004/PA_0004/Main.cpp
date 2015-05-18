#include <iostream>          

using namespace std;

void divisores_rec(int a, int b);
void divisores(int a);

//const int MAX = 99;
//int myArr[MAX];
//int myArrIndex = 0;

int main(int argc, char* argv[]){

	divisores(21);

	/*for (int i = 0; i < myArrIndex; i++){
		cout << myArr[i] << endl;
	}*/

	system("pause");

	return 1;
}

void divisores(int a){
	divisores_rec(a, a);
}

void divisores_rec(int a, int b)
{
	if (b == 1) {
		/*myArr[myArrIndex++] = b;*/
		cout << b << endl;
		return;
	}		
		
	if (a % b == 0){			
		/*myArr[myArrIndex++] = b;*/
		cout << b << endl;
	}

	return divisores_rec(a, b-1);	
}
