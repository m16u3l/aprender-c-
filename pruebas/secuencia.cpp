#include <iostream>

using namespace std;

/*
	mostrar una secuancia de enteros al reves
	15 3 4 2 1 9 -1 -7 5 0
	0 5 -7 -1 9 1 2 4 3 15
*/

struct Eslabon
{
	int num;
	Eslabon *anterior;
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Eslabon *actual = 0;
	while(n != 0)
	{
		Eslabon *nuevo = new Eslabon;
		nuevo->num = n;
		nuevo->anterior = actual;
		actual = nuevo;
		cin >> n;
	}

	while(actual != 0)
	{
		cout << actual->num << ' ';
		actual = actual->anterior;
	}

	return 0;
}

