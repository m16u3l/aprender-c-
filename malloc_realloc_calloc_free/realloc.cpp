#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char* b = (char*)malloc(2);
    b[0] = 'h';
    b[1] = '\0';

    cout<<b<<endl;
    //realloc(puntero, nuevo tamano)
    b = (char*)realloc(b, 6);   //busca un espacio libre despues del puntero para aumentarlo
    strcpy(b+1, "ello");       //b+1 es un puntero
    cout<<b<<endl;

    free(b);
    return 0;
}
