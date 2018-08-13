#include <iostream>
#include <vector>

using namespace std;

void incr(int& i)   //paso por referencias por valor
{
    i++;
}


struct Punto
{
    float x, y;	
};

struct ListaPuntos
{
    Punto puntos[100];
    int nPuntos;
};

int main(int argc, char const *argv[])
{
    /*
    int a = 1;
    incr(a);
    cout << a << endl;
    */

    /*
    int a = 1;
    int& i = a; //i es una referencia a un entero (inicializadad con la variable a)

    i++;    //es lo mismo que hacer a++;

    cout << a << endl;
    */

    ListaPuntos L;
    L.nPuntos = 50;
    // ....

    float& x = L.puntos[L.nPuntos -1].x;
    x = x + 2.0;

    Punto origen = {0.0, 0.0};

    float& _x = origen.x;
    if (_x >0.0)
    {
    }
    else
    {
        if (_x > -5.0)
        {
        }

    }

    vector<int> v(10, 2);
    int& r = v[5];
    r = r * 2;
    cout << v[5] << endl;
    return 0;
}
