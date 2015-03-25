#include "JogoGloria.h"
#include <iostream>
#include <string>

int main(int argc, char*argv[])
{
	casa* raizJogo = NULL;
	casa* caudaJogo = NULL;
	jogador* raizJogador = NULL;

	bool canProceedToGame = gameSetup(raizJogo, caudaJogo, raizJogador, 0);
	
	if (canProceedToGame)
		gameLoop(raizJogo, caudaJogo, raizJogador);	
	
	system("pause");
}