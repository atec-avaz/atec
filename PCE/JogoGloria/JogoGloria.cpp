#include "JogoGloria.h"

bool dadoInit = false;

void init(){
	seedRandomNumber(1023, 1, 6);
}

int lancarDado(){
	if (!dadoInit)
	{
		dadoInit = true;
		init();
	}
	return getRandomNumber();
}

bool gameSetup(casa *& raizJogo, casa *& caudaJogo, jogador* &raizJogador, int size){
	bool gameCanStart = true;

	// definir um random para obter o numero de casas
	srand(1024); 
	int sizeTabuleiro = 10 + rand() % 20;

	// inicializar o tabuleiro de jogo
	inicializaTabuleiro(raizJogo, caudaJogo, sizeTabuleiro);

	// inicializar os jogadores
	inicializaJogadores(raizJogador, raizJogo);

	// randomizar os jogadores
	randomizaJogadores(raizJogador);
	
	return gameCanStart;
}

void gameLoop(casa* raiz, casa* cauda, jogador* raizJogadores){
	jogador* jogadorActual = raizJogadores;
	
	while (true){		
		imprimirTabuleiro(raiz, raizJogadores);

		imprimirJogador(jogadorActual);

		system("pause");

		cout << "Lancou dado, saiu valor: " << fazerJogada(jogadorActual) << endl;

		system("pause");
		system("cls");
		
		if (verificarVitoria(raiz, raizJogadores)){
			cout << "Jogador " << jogadorActual->peca << "=>" << jogadorActual->nome.c_str() << " foi o vencedor" << endl;
			break;
		}
		
		alternarJogador(jogadorActual);		
	}


}
void imprimirJogador(jogador* jogadorActual){
	cout << endl << "Jogador: " << jogadorActual->nome.c_str() << "[" << jogadorActual->peca << "]";
}

int fazerJogada(jogador* jogadorActual){
	int jogada = lancarDado();
	casa* casaActual = jogadorActual->place;
	bool jogadaValida = false;
	for (int i = 0; i < jogada; i++)
	{ 
		jogadaValida = true;
		casaActual = casaActual->next;
		if (casaActual == NULL && i < jogada - 1){
			jogadaValida = false;
			break;
		}
	}

	if (jogadaValida)
		jogadorActual->place = casaActual;

	return jogada;
}

bool verificarVitoria(casa* raiz, jogador* raizJogador){
	jogador* iterJogador = raizJogador;

	// alternativamente seria mais inteligente utilizar o apontador "cauda" ...
	while (raiz->next != NULL)
		raiz = raiz->next;
	
	do {
		// iterar os jogadores
		// casoalgum esteja na ultima casa então ganhou
		if (iterJogador->place == raiz)
			return true;

		iterJogador = iterJogador->next;
	} while (iterJogador != raizJogador);
	
	return false;
}

void alternarJogador(jogador* &jogadorActual){
	jogadorActual = jogadorActual->next;
}

void inicializaTabuleiro(casa* &head, casa* &tail, int size){
	for (int i = 0; i < size; i++){
		casa *novo = new casa;
		novo->numero = i + 1;
		novo->next = NULL;

		if (head == NULL){
			head = novo;
			tail = novo;
		}
		else
		{
			tail->next = novo;
			tail = novo;
		}		
	}
}

void inicializaJogadores(jogador*& raiz, casa* raizJogo){
	string nomes[] = { "Manuel", "Maria", "Jose", "Joao", "Eduardo", "Mariana" };
	char pecas[] = { 'C', 'H', 'P', 'J', 'K', 'W' };
	srand(1024);
	int nJogadores = 2 + rand() % 4;
	for (int i = 0; i < nJogadores; i++){
		inserirJogador(raiz, raizJogo, nomes[i], i+1, pecas[i]);
	}
}

void randomizaJogadores(jogador *& raizJogador){
	jogador* jogadorIter = raizJogador;
	do{
		jogadorIter->numero = lancarDado();
		jogadorIter = jogadorIter->next;
	} while (jogadorIter != raizJogador);
	
	ordenarListaDesc(raizJogador);	
}

void inserirJogador(jogador* &raiz, casa* raizJogo, string nome, int numero, char peca){
	jogador* novo = new jogador;
	novo->nome = nome;
	novo->numero = numero;
	novo->peca = peca;
	novo->place = raizJogo;
	
	jogador * last = raiz;
	if (last == NULL){
		raiz = novo;
	}
	else{
		while (last->next != raiz)
			last = last->next;

		last->next = novo;
	}

	novo->next = raiz;
}


void ordenarListaDesc(jogador * & raiz)
{
	if (raiz != NULL)
	{
		jogador* current = raiz; jogador* prev = 0; jogador* tempNode = 0; bool hasChanges = false;
		jogador* last = raiz;

		while (!hasChanges)
		{
			while (current->next != raiz)
			{
				while (last->next != raiz)
					last = last->next;

				tempNode = current->next;

				if (current->numero < tempNode->numero)
				{
					hasChanges = true;
					current->next = tempNode->next;
					tempNode->next = current;

					if (prev != NULL)  prev->next = tempNode;

					prev = tempNode;

					if (raiz == current){ 
						raiz = tempNode; 
						last->next = raiz;
					}
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



void imprimirTabuleiro(casa*raiz, jogador* raizJogadores){
	int nCasas = 6;
	casa* casaActual = raiz;
	while (casaActual != NULL){
		string strJogador = "";

		jogador* jogadorIter = raizJogadores;
		do{
			if (jogadorIter->place == casaActual){
				if (strJogador.size() == 0)
					strJogador = strJogador + jogadorIter->peca;
				else
					strJogador = strJogador + "," + jogadorIter->peca;
			}
			jogadorIter = jogadorIter->next;
		} while (jogadorIter != raizJogadores);

		cout << casaActual->numero << "[" << strJogador.c_str() << "]  \t";
		if (nCasas-- <= 0){
			cout << endl;
			nCasas = 6;
		}

		casaActual = casaActual->next;
	}

	cout << endl << endl;
}