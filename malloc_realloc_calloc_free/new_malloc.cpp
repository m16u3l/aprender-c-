#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

//reservas de memoria con void*
int main(int argc, char const *argv[])
{
    //mallo devuelve un puntero a variable void* donde hay 4bytes
    void* p = malloc(sizeof(int));	//malloc reserva memoria, void* no tiene tipo de memoria

    cout<<*((int*)p)<<endl;

    int* q = (int*)p;
    *q=8;
    cout<<*q<<endl;

    char* r = (char*) p;
    strcpy(r, "bye");

    cout<<r<<endl;
    cout<<*q<<endl;	

    free(r);
    return 0;
}