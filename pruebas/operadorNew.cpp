#include <iostream>

using namespace std;

//new: reserva memoria en el Heap(zona nde memoria dinamica)

/*
Versiones de new
1. para un soo dato de tipo basico
	(int, char, bool, double...)
2. para una tabla de tipo basico
	(int, char, bool, double...)

3. para un struc
	
4. para una clase
*/

struct Punto
{
	double x, y;
};

class Circulo
{
	double _radio, _cx, _cy;

public:
	Circulo(double r, double cx, double cy)
	:_radio(r), _cx(cx), _cy(cy)
	{};

	double radio() const
	{
		return _radio;
	}
	//~Circulo();
};

int main(int argc, char const *argv[])
{
	//int t[10];	//esta tabla se reserva ne la pila

	//1.
	int *p_entero = new int;	//devuelve un puntero a un entero que se reserva en el Heap
	*p_entero = 1;
	cout << *p_entero << endl;

	//2.
	int *p_tabla = new int[10];
	*p_tabla = 1;
	*(p_tabla + 3) = 4;	//p_tabla[3] = 4;

	for (int i = 0; i < 10; ++i)
	{
		cout << p_tabla[i] << endl;
	}

	//3.
	Punto *p_punto = new Punto;
	p_punto->x = 1.0;
	(*p_punto).y = 2.0;

	//4.
	Circulo *p_circulo = new Circulo{10.0, 0.0, 0.0};
	cout << p_circulo->radio() << endl;
	cout << (*p_circulo).radio() << endl;

	return 0;
}
