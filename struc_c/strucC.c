#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct //cambiar
{
    char* name;
    int id;

} Person;

void init_person(Person* p, const char* n, int id){
    size_t len = strlen(n);
    p->name = (char*)malloc(len+1);
    memcpy(p->name, n, len+1);
}

void free_person(Person* p){
    free(p->name);
}

int main()
{

    /*
    struct Person p;       //en C
    */
    Person p;
    init_person(&p, "Juan Perez", 645);

    puts(p.name);

    free_person(&p);
/*
    Person* q = &p;  //*q=p
    Person& r = p;  // r=p;

    Person*& s = q;    //
*/
    return 0;
}