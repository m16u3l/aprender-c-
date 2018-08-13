#include <iostream>

using namespace std;

void sum(int a, int b)
{
    cout<<a+b<<endl;
}

void sub(int a, int b)
{
    cout<<a-b<<endl;
}

void r(){
    cout<<"hola"<<endl;
}

int main(int argc, char const *argv[])
{
    //puntero a una funcion
    //la variable es p, el puntero es *p
    void (*p)(int, int);//int q;

    p = sum;

    p(6, 10);

    p = sub;

    p(20, 5);

    //no compila porque r tiene otra signatura
    //p = r;

    return 0;
}