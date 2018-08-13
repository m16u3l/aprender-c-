#include <iostream>
using namespace std;

size_t mylen(const char* t){
    size_t n = 0;
    while(t[n] != '\0'){
        n++;
    }
    return n;
}

/*
* "hola, hoy es viernes 6 de octubre" -> 7
*/
size_t count_words(const char* t){
    size_t res = 0;
    while(*t != '\0'){
        if(*t == ' '){
            res++;
            *t++;
        } else {
            *t++;
        }
    }
    res++;
    return res;
}

/*
* "hola, hoy es viernes 7 de octubre" "es" -> 1
*/
size_t count_ocurrences(const char* t, const char* w){
    size_t res = 0;
    size_t k = 0;
    size_t i = 0;

    size_t lent = mylen(t);
    size_t lenw = mylen(w);

    int f[lent];

    while(k < lent){
        if(t[i] == w[k+i]){
            if(i == lenw - 1){
                res = k;
            }
            i++;
        } else {
            k = k + i-f[i];
            if(i > 0){
                i = f[i];
            }
        }
        cout<<k<<"\n";
        k++;
    }
    return res;
}

int main(){
    const char* text = "hola, hoy es viernes 6 de octubre";
    const char* word = "es";

    size_t size = count_words(text);
    cout<<size<<"\n";
    size_t ocurrences = count_ocurrences(text, word);
    cout<<ocurrences<<"\n";
}
