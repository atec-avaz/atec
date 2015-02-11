#ifndef __MYSTACK
#define __MYSTACK

#include "iostream"

typedef struct {
	int *arrayStack;
	int arrayStackSize;
	int topoStack;
} Stack;

bool createStack(Stack*,int limite);
void destroyStack(Stack*);
bool emptyStack(Stack*);
bool fullStack(Stack*);
bool push(int valor, Stack*);
int pop(Stack*);
int peek(Stack*);

#endif // !__MYSTACK

