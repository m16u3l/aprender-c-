#include <iostream>

using namespace std;

/*
	dos versiones
1. para reservas de objetos unicos

2. para reservas de matrices
*/

int main(int argc, char const *argv[])
{
	int *p = new int;
	*p = 1;
	cout << *p << endl;
	delete p;
	
	int *p2 = new int[1000];
	for (int i = 0; i < 1000; ++i)
	{	
		p2[i] = i + 1;
	}
	delete[] p2;
	return 0;
}
