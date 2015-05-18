#include <iostream>

using namespace std;


void troca(int &x, int &y);
void troca1(int &x, int * y);
void troca2(int * x, int * y);

int main(int argc, char* argv[])
{
	int a = 10, b = 20;	
	int x = 40, y = 50;
	int * px = &x, *py = &y;

	cout << "a=" << a << ", b=" << b << endl;
	troca(a, b);	
	cout << "a=" << a << ", b=" << b << endl;
	system("pause");

	cout << "x=" << x << ", py=" << y << endl;
	troca1(x, py);
	cout << "x=" << x << ", py=" << y << endl;

	system("pause");

	cout << "px=" << *px << ", py=" << *py << endl;
	troca2(px, py);
	cout << "px=" << *px << ", py=" << *py << endl;

	system("pause");
	return 1;
}

void troca(int &x, int &y){
	int aux = y;
	y = x;
	x = aux;
}

void troca1(int &x, int * y){
	int aux = *y;
	*y = x;
	x = aux;
}

void troca2(int * x, int * y){
	int aux = *y;
	*y = *x;
	*x = aux;
}

void f(int t[]){

}

