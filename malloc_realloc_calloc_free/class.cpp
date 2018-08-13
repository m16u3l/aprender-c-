#include <iostream>

using namespace std;

void b()
{
    cout<<"HI"<<endl;
}

void c()
{
    cout<<"BYE"<<endl;
}

void d()
{

}


void a(void (*p)(), void (*q)())
{
    p();
    q();
}

int main(int argc, char const *argv[])
{
    a(b, c);
    return 0;
}