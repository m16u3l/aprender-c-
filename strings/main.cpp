#include <iostream>
using namespace std;

size_t mylen(const char* s){
    size_t n = 0;
    while(s[n] != '\0'){
        n++;
    }
    return n;
}

char*  mycopy(char* s5, const char* s4){
    while(*s4 != '\0'){
        *s5++ = *s4++;
    }
    *s5 = '\0';
    return s5;
}

char*  myconcat(char* s5, const char* aux){
    size_t pos = mylen(s5);
    mycopy(s5+pos, aux);
    return s5;
}

int main(){
    char s1[]={'h','e','l','l','o','\0'};
    char s2[]="hola";
    const char* s4 = "hola mundo";
    char s5[100];

    cout<<mycopy(s5, s4)<<"\n";
    cout<<myconcat(s5,"c++")<<"\n";
}
