#ifndef __MYSTACK
#define __MYSTACK

#include "iostream"

bool createStack(int limite);
void destroyStack();
bool emptyStack();
bool fullStack();
bool push(int valor);
int pop();
int peek();

#endif // !__MYSTACK

