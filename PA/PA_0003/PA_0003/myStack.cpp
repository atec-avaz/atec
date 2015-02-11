#include "myStack.h"

bool createStack(Stack* myReturnStack, int limite){
	myReturnStack->arrayStack = new int[limite];
	myReturnStack->arrayStackSize = limite;
	myReturnStack->topoStack = -1;
	return true;
}

void destroyStack(Stack* lv_stack){
	delete[] lv_stack->arrayStack;
	lv_stack->arrayStack = NULL;
	lv_stack->arrayStackSize = -1;
	lv_stack->topoStack = -1;
}

bool emptyStack(Stack* lv_stack){
	return lv_stack->topoStack == -1;
}

bool fullStack(Stack* lv_stack){
	return lv_stack->topoStack == (lv_stack->arrayStackSize - 1);
}

bool push(int valor, Stack* lv_stack){
	bool pushSucess = false; // por defeito não conseguimos introduzir, até prova do contrario
	if (lv_stack->topoStack < lv_stack->arrayStackSize - 1){
		// temos espaço na stack
		lv_stack->arrayStack[lv_stack->topoStack + 1] = valor;
		lv_stack->topoStack++;
		pushSucess = true;
	}
	return pushSucess;
}

int pop(Stack* lv_stack){
	if (lv_stack->topoStack > -1){
		return lv_stack->arrayStack[lv_stack->topoStack--];
	}
	return NULL;
}

int peek(Stack* lv_stack){
	if (lv_stack->topoStack > -1){
		return lv_stack->arrayStack[lv_stack->topoStack];
	}
	return NULL;
}
