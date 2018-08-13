#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t[] = { -1, 7, 4};
    int *p;
/*
    //el nombre de una tabla es un puntero a su primer elemento
    //p = &t[0];	//p = t;  &t[0] = t;
    p = t;
    *p = 3;

    *(p + 1) = -2;	//t[1] = -2;

    //t[2] = 15;
    p[2] = 15;	//*(p + 2) = 15;
*/

    p = &t[1];
    //p[0] = 3;
    p[-1] = 0;	//*(p - 1) = 0;

    int k;
    for (int k = 0; k < 3; k++)
    {
        cout << t[k] << " " << endl;
    }

    return 0;
}