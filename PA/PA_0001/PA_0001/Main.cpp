#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int arrayStackSize = 5;
int arrayStack[arrayStackSize];
int topoStack = -1;

bool createStack(int limite);
void destroyStack();
bool emptyStack();
bool fullStack();
bool push(int valor);
int pop();
int peek();

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

bool createStack(int limite){
	return true;
}

void destroyStack(){
	topoStack = -1;
}

bool emptyStack(){
	return topoStack == -1;
}

bool fullStack(){
	return topoStack == (arrayStackSize - 1);
}

bool push(int valor){
	bool pushSucess = false; // por defeito não conseguimos introduzir, até prova do contrario
	if (topoStack < arrayStackSize - 1){
		// temos espaço na stack
		arrayStack[topoStack + 1] = valor;
		topoStack++;
		pushSucess = true;
	}
	return pushSucess;
}

int pop(){
	if (topoStack > -1){
		return arrayStack[topoStack--];
	}
	return NULL;
}

int peek(){
	if (topoStack > -1){
		return arrayStack[topoStack];
	}
	return NULL;
}