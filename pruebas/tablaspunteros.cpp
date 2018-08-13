#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char palabra[5] = {'h', 'o', 'l', 'a', char(0)};
    const char *pc;

    // "adios" = {'a', 'd', 'i', 'o', 's', char(0)}
    pc = "adios";


    for (int i = 0; i < 6; ++i)
    {
        cout << "codigo: " <<int(pc[i]) << " caracter: " << pc[i] << endl;
    }
    cout << "palabra: " << palabra <<endl;
    cout << "puntero: " << pc << endl;

    return 0;
}