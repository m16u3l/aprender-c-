#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 2;
	char c = 'c';

	//en este ejemplo  (x -> y) == x apunta y 
	int *p = &a;	//p -> a
	p = &b;			//p -> b 

	p = &a;
	*p = 5;
	p = &b;
	*p = 6;
	//p = &c;

	cout << "valor de a: " << a << endl;
	cout << "direccion de memoria de a: " << long(&a) << "\n\n";
	cout << "valor de b: " << b << endl;
	cout << "direccion de memoria de b: " << long(&b) << "\n\n";
	cout << "valor de p: "<< long(p) << endl;
	cout << "direccion de memoria de p: " << long(&p) << "\n\n";
	return 0;
}