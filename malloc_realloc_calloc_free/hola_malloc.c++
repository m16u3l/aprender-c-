#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //char** rr = char[10];

    //char* r = malloc(15); //c
    char* r = (char*)malloc(15); //c++

    strcpy(r, "hello world");

    puts(r);

    free(r);
    //free(null);   //c
    free(nullptr);  //c++
    return 0;
}
