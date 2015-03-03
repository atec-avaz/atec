#include "myStack.h"

int * arrayStack;
int arrayStackSize = -1;
int topoStack = -1;

//// estas vari�veis s�o definidas como externas porque 
//// foram declaradas fora deste include e s�o vari�veis globais
//extern int * arrayStack;
//extern int arrayStackSize;
//extern int topoStack;

bool createStack(int limite){
	if (arrayStack == nullptr){
		arrayStack = new int[limite];
		arrayStackSize = limite;
		return true;
	}

	return false;
}

void destroyStack(){
	delete[] arrayStack;	
	arrayStack = NULL;
	arrayStackSize = -1;
	topoStack = -1;
}

bool emptyStack(){ 
	return topoStack == -1; 
}

bool fullStack(){ 
	return topoStack == (arrayStackSize - 1); 
}

bool push(int valor){ 
	bool pushSucess = false; // por defeito n�o conseguimos introduzir, at� prova do contrario
	if (topoStack < arrayStackSize - 1){
		// temos espa�o na stack
		arrayStack[topoStack+1] = valor;
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