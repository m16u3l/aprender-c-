#include <cstdlib> //c++
//#include <stdlib.h> //C

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 8;

    int* p = (int*) malloc(n * sizeof(int)); //reserva la memoria 

    /*
    char* s = new char[10];
    char* s = (int*) malloc(10 * sizeof(char));
    */

    if (p == nullptr)
    {
        exit(-2);
    }

    p[0] = 8;
    p[1] = 45;

    cout<<p[1]+p[0]<<endl;
    cout<<p[2]<<endl;

    free(p);            //libera la memoria
    free(nullptr);

    return 0;
}
