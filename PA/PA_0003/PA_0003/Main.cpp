#include <iostream>
#include <string>
#include <stdio.h>
#include "myStack.h"

using namespace std;

void changeMe(int &var){
	int* aux;	
	aux = &var;	

	cout << aux << endl;
	cout << *aux << endl;
	
	*aux = 15;

	cout << &var << endl;
	cout << var << endl;
	cout << *&var << endl;
}

void changeMeAlso(int* var){
	*var = 16;
}

int main(int argc, char* argv[]){
	int n = 10;
	changeMe(n);
	cout << n <<endl;

	changeMeAlso(&n);
	cout << n << endl;
	
	Stack myStk;
	createStack(&myStk, 6);

	int valor = 10;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor, &myStk)) cout << "N�o foi poss�vel inserir" << endl; else cout << "Inserido=>" << valor++ << endl;

	int res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop(&myStk);
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	
	destroyStack(&myStk);
	system("pause");
	return 1;
}