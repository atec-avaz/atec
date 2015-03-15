#include <iostream>

using namespace std;

struct node{
	int valor;
	node* next;
};

void inserirNoFinal(node * &raiz, int numero);
const int MAX_SIZE = 10;
void calcularValores2(int arr[], int *soma, float *media);
void calcularValores(int arr[], int &soma, float &media);
void troca1(int &valor1, int &valor2);
void troca2(int *valor1, int *valor2);

int main()
{
	
	// Cabeça da lista
	node * root = NULL;

	int i = 0;
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);

	
	node* iter = root;
	int posicao = 0;
	do {
		cout << "Posicao " << posicao++ << " => " << iter->valor << endl;
		iter = iter->next;
	} while (iter != NULL);

	system("pause");
}

void inserirNoFinal(node * &raiz, int numero){
	node * novo;
	
	novo = new node;
	novo->valor = numero;
	novo->next = NULL;

	node * last;
	last = raiz;
	if (last == NULL){
		raiz = novo;
	} else{
		while (last->next!=NULL){
			last = last->next;
		}
		if (last != NULL)
			last->next = novo;
	}	
}

void calcularValores2(int arr[], int *soma, float *media){
	for (int i = 0; i < MAX_SIZE; i++){
		*soma += arr[i];
	}
	*media = (float) *soma / (float)MAX_SIZE;
}


void calcularValores(int arr[], int &soma, float &media){
	for (int i = 0; i < MAX_SIZE; i++){
		soma += arr[i];
	}
	media = (float) soma / (float) MAX_SIZE;
}

void troca1(int &valor1, int &valor2){
	int tmp;
	tmp = valor1;
	valor1 = valor2;
	valor2 = tmp;
}

void troca2(int *valor1, int *valor2){
	int tmp;
	tmp = *valor1;
	*valor1 = *valor2;
	*valor2 = tmp;
}
