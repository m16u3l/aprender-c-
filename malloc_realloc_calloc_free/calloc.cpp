/*
P.O.D.s (Plain Old Data)
*tipo primitivo
    int
*arrays de PODs
    int[]
*estructuras de PODs
    class X{
    public:
        int y;
        int z;
        char x[10];
    }
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    //array de 100 enteros
    //malloc
    int* e = (int*)malloc(10000*sizeof(int));
    memset(e, 0xBA, 10000*sizeof(int));	//coloca 0 en toda la reserva

    /*//calloc
    int* e = (int*)calloc(10000, sizeof(int));
    */

    char* b = (char*)malloc(2);
    b[0] = 'h';
    b[1] = '\0';

    for(int i=0; i<10000; i++){
        cout<<(unsigned)e[i]<<endl;
    }
    free(e);
    return 0;
}
