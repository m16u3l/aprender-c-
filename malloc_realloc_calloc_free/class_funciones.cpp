#include <iostream>

using namespace std;

typedef void (*FUNC)();
typedef size_t (*FUNC2)();
typedef void (*Action)();	//cambia de nombre, no crea nuevos tipos

void b()
{
    cout<<"HI"<<endl;
}

void c()
{
    cout<<"BYE"<<endl;
}
/*
void d(FUNC2 p)
{

}


void e(FUNC2 p)
{

}
*/
//void a(void (*p)(), void (*q)())

void a(FUNC p, FUNC q)
{
    p();
    q();
}
/*
void a(FUNC2 d, FUNC2 e)
{
    cout<<p<<endl;
    cout<<d<<endl;
}*/

void a1()
{

}
void a2()
{

}
void a3()
{

}


int main(int argc, char const *argv[])
{
    Action a[] = {a1, a2, a3};

    //a siempre tiene que ser a[], si es a{} no se puedo recorrer el for

    //cada refernecia de p es una 
    for (const auto& p:a)//referencia a una funcoin constante que esta en un array
    //for (auto p:a)    //c++11
    {
        p();
    }

    /*
    a(b, c);

    size_t d = 1;
    size_t e = 2;
    //a(d, e);
    */
    return 0;

    //en c para hacer polimorfismo se crean variable a funciones
}
