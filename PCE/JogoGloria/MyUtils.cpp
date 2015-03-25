#include "MyUtils.h"

int RANDOM_MIN = 1;
int RANDOM_MAX = 6;
int RANDOM_SEED = 1024;

void seedRandomNumber(int seed, int min, int max){
	RANDOM_SEED = seed;
	RANDOM_MIN = min;
	RANDOM_MAX = max;
	srand(RANDOM_SEED);
}

int getRandomNumber(){
	if (RANDOM_MIN >= RANDOM_MAX)
		return NULL;

	return RANDOM_MIN + rand() % RANDOM_MAX;
}

int lerInteiro(){
	int opc = NULL;
	bool valorLido = false;
	do{
		cin >> opc;
		if (cin.fail())
		{
			cout << "Introduza apenas numeros" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			valorLido = false;
		}
		else
			valorLido = true;
	} while (!valorLido);

	return opc;
}












