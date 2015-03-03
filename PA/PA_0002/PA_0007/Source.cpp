#include <iostream>

using namespace std;

int doStuff(int v[], int k, int i, int s);

int main(int argc, char* argv[])
{
	int teste[100];
	for (int i = 0; i < 100; i++){
		teste[i] = i*2;
	}

	int res = doStuff(teste, 50, 0, 99);
	if (res != -1)
		cout << "Stuff:" << res << endl;
	else
		cout << "No stuff!" << endl;

	system("pause");
	return 1;
}


int doStuff(int v[], int k, int i, int s)
{
	if (i > s)
		return -1;

	int m = (i + s) / 2;
	if (k == v[m])
		return m;
	else
	{
		if (k < v[m])
			return doStuff(v, k, i, m - 1);
		else
			return doStuff(v, k, m + 1, s);
				
	}
		
}
