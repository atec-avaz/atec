#include <iostream>

using namespace std;

struct node{
	int valor;
	node* next;
};

struct jogador{
	int numero;
	string nome;
	char peca;
	jogador* next;
};

void inserirNoInicio(node * & raiz, int numero);
void inserirNoFinal(node * &raiz, int numero);
void inserirDepoisDe(node * & raiz, int numero, int pesquisa);
void listarLista(node* ap);
void ordenarListaAsc(node * & raiz);
void ordenarListaDesc(node * & raiz);

int main()
{	
	// raiz
	node * root = NULL;
	int i = 1;
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, i++);
	inserirNoFinal(root, 10);

	inserirNoInicio(root, 50);
	inserirDepoisDe(root, 7850, 50);

	listarLista(root);

	ordenarListaAsc(root);	
	listarLista(root);

	ordenarListaDesc(root);
	listarLista(root);
	


	cout << "António Vaz" << endl;

	system("pause");
}

void listarLista(node* ap){
	int posicao = 0;
	do {
		cout << "Posicao " << posicao++ << " => " << ap->valor << endl;
		ap = ap->next;
	} while (ap != NULL);
}

void inserirDepoisDe(node * & raiz, int numero, int pesquisa){
	node * novo;
	novo = new node;
	novo->valor = numero;
	
	// ligações
	if (raiz == NULL){
		// lista vazia
		novo->next = NULL;
		raiz = novo;
	}
	else{
		// Lista com elemento(s)
		node* iter = raiz;
		while (iter->next != NULL){
			if (iter->valor == pesquisa)
				break;

			iter = iter->next;
		}

		novo->next = iter->next;
		iter->next = novo;
	}

}

void inserirNoInicio(node * & raiz, int numero){
	node * novo;
	novo = new node;
	novo->valor = numero;
	novo->next = raiz;
	raiz = novo;
}

void inserirNoFinal(node * & raiz, int numero){
	node * novo;
	novo = new node;
	novo->valor = numero;
	novo->next = NULL;

	node * last;
	last = raiz;
	if (last == NULL){
		raiz = novo;
	}
	else{
		while (last->next != NULL){
			last = last->next;
		}
		if (last != NULL)
			last->next = novo;
	}
}

void ordenarListaAsc(node * & raiz)
{	if (raiz != NULL)
	{	node* current = raiz; node* prev = 0; node* tempNode = 0; bool hasChanges = false;

		while (!hasChanges)
		{
			while (current->next != NULL)
			{
				tempNode = current->next;

				if (current->valor > tempNode->valor)
				{
					hasChanges = true;
					current->next = tempNode->next;
					tempNode->next = current;
					
					if (prev != NULL)  prev->next = tempNode;

					prev = tempNode;

					if (raiz == current) raiz = tempNode;					
				}
				else
				{   prev = current;
					current = current->next;
				}
			}
			if (hasChanges == false)
				break;
			else
			{
				prev = NULL;
				current = raiz;
				hasChanges = false;
			}
		}
	}
}


void ordenarListaDesc(node * & raiz)
{
	if (raiz != 0)
	{
		node* current = raiz;
		node* prev = 0;
		node* tempNode = 0;
		bool hasChanges = false;

		while (!hasChanges)
		{
			while (current->next != 0)
			{
				tempNode = current->next;

				if (current->valor < tempNode->valor)
				{
					hasChanges = true;
					current->next = tempNode->next;
					tempNode->next = current;

					if (prev != NULL)
						prev->next = tempNode;

					prev = tempNode;
					if (raiz == current)
						raiz = tempNode;
				}
				else
				{
					prev = current;
					current = current->next;
				}
			}
			if (hasChanges == false)
				break;
			else
			{
				prev = NULL;
				current = raiz;
				hasChanges = false;
			}
		}
	}
}
//
//void inserirJogador(jogador * & raiz, ){
//
//}
