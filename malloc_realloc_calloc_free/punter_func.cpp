#include <iostream>

using namespace std;

//funcion que sabe comparar numeros
int fc(const void* a, const void* b)
{
    int* p = (int*) a;
    int* q = (int*) b;

    return *p - *q;
}

//ejemplo de punteroa funciones
int main(int argc, char const *argv[])
{
    int s[] = {6,8,1,0,2,4,9};

    //array void*, puntero al array numero de elementos, el tamanio de cada elemento, funcion que sepa comparar enteros
    qsort(s, 7, sizeof(int), fc);//llama a la funcoin fc

    for(int e:s)
    {
        cout<<e<<endl;
    }
    return 0;
}