#include <iostream>
#include <cstring>
//#include "student.h"

using namespace std;

class persona
{
private:
    char nombre[32];
    char apellido[32];
    size_t edad;

public:
    persona(const char* nombre, const char* apellido, size_t edad)
    {
        strcpy(this->nombre,nombre);
        strcpy(this->apellido,apellido);
        this->edad = edad;
    }

    void show() const
    {
        cout<<nombre<<" "<<apellido<<"\n";
    }
};

class student
{
    size_t id;
    char* name;
public:
    student(size_t id, const char* name)
    {
        this->id = id;
        size_t len = strlen(name);
        this->name = new char[len+1];
        strcpy(this->name,name);
    }
    void show(){
    cout<<name<<'\n';
    }
};

/*
student subscribe(){
    char h[] = "Juan Lopez";
    return student{456, h};
}*/

int main()
{
    int q{10};
    cout<<q<<"\n";
    persona p{"Evo", "Perez", 60};
    persona p1{"Alguien", "nuevo", 20};
    p.show();
    p1.show();

    student s1{123, "Omar Vera"};
    s1.show();

//  student s2 = subscribe();
//  s2.show();
}
