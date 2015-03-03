#include <iostream>
#include <cstdlib>
#include <sys/timeb.h>

using namespace std;

const int MIN = 1;
const int MAX = 9000;
const int VEC_SIZE = 99999;

int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if (nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

void insertionSort(int numeros[], int tam) {
	int i, j, eleito;
	for (i = 1; i < tam; i++){
		eleito = numeros[i];
		j = i - 1;
		while ((j >= 0) && (eleito < numeros[j])) {
			numeros[j + 1] = numeros[j];
			j--;
		}
		numeros[j + 1] = eleito;
	}
}

void sort_array(int ar[]){
	for (int x = 0; x < VEC_SIZE; x++)
	{
		int index_of_min = x;
		for (int y = x; y < VEC_SIZE; y++)
		{
			if (ar[index_of_min] > ar[y]){
				index_of_min = y;
			}
		}
		int temp = ar[x];
		ar[x] = ar[index_of_min];
		ar[index_of_min] = temp;
	}
}

void randomize_array(int ar[]){
	for (int i = 0; i < VEC_SIZE; i++){
		ar[i] = rand() % MAX + MIN;
	}
}

void print_array(int ar[]){
	cout << "Content of array:" << endl;
	for (int i = 0; i < VEC_SIZE; i++){
		cout << ar[i] << endl;
	}
}

int main(int argc, char* argv[]){
	int arr[VEC_SIZE];
	int start = 0, milliSecondsElapsed = 0;

	// Inicializar o array
	start = getMilliCount();	
	randomize_array(arr);
	milliSecondsElapsed = getMilliSpan(start);
	cout << "Elapsed time to randomize = " << milliSecondsElapsed <<  " milliseconds" << endl;

	// Ordenar o array
	start = getMilliCount();
	//insertionSort(arr, VEC_SIZE);
	sort_array(arr);
	milliSecondsElapsed = getMilliSpan(start);
	cout << "Elapsed time to sort = " << milliSecondsElapsed << " milliseconds" << endl;

	// Imprimir o array, ATENÇÃO AO NUMERO DE ELEMENTOS DO ARRAY, PODEM COLAR O CPU
	//print_array(arr);

	system("pause");
	return 1;
}