#include <iostream>
#include <string>
#include <stdio.h>
#include "myStack.h"

using namespace std;

int * arrayStack;
int arrayStackSize = -1; 
int topoStack = -1;

int main(int argc, char* argv[]){
	
	createStack(5);
	int valor = 10;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;
	if (!push(valor)) cout << "Não foi possível inserir" << endl; else cout << "Inserido=>" << valor++ << endl;

	int res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	res = pop();
	if (res == NULL) cout << "Stack vazia" << endl; else cout << "Valor retirado =>" << res << endl;
	
	destroyStack();	
	system("pause");
	return 1;
}
