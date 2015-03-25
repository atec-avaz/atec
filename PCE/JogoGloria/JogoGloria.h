#ifndef __JOGOGLORIA__
#define __JOGOGLORIA__ 1

#include <iostream>
#include "MyUtils.h"

struct casa{
	int numero;
	casa* next;
};

struct jogador{
	int numero;
	string nome;
	char peca;
	jogador* next;
	casa* place;
};


int lancarDado();
void init();
bool gameSetup(casa*&, casa*&, jogador*&, int);
void gameLoop(casa* raiz, casa* cauda, jogador* raizJogadores);
void inicializaTabuleiro(casa* &head, casa* &tail, int size);
void inicializaJogadores(jogador*& raiz, casa*);
void randomizaJogadores(jogador *& raizJogador);
void inserirJogador(jogador* &raiz, casa* raizJogo, string nome, int numero, char peca);
void ordenarListaDesc(jogador * & raiz);

void imprimirTabuleiro(casa*raiz, jogador* raizJogadores);

void imprimirJogador(jogador* jogadorActual);
int fazerJogada(jogador* jogadorActual);
bool verificarVitoria(casa* raiz, jogador* raizJogador);
void alternarJogador(jogador* &jogadorActual);
#endif