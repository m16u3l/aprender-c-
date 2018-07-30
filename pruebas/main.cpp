#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int t[5] = {1, 2, 3, 4, 5};

	int *p;
	p = &t[0];

	*(p + 1) = 8;

	cout << long(&t[0]) << "\n";
	cout << long(&t[1]) << "\n";
	cout << long(&t[2]) << "\n";
	cout << long(&t[3]) << "\n";
	cout << long(&t[4]) << "\n";

	cout << "valor de p: "<< long(p) << endl;
	cout << "direccion de memoria de p: " << long(&p) << "\n";
	cout << "el valor de la direccion de memoria de *p es: " << *(p+1) << "\n";

	//cout << "seria como escribir t[x]: "<< t[4] << "\n";
	return 0;
}
