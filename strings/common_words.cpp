#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ifstream in("file.txt");

    if(!in){
        cerr << "Could not open file.txt.";
        return EXIT_FAILURE;
    }

    string str, str2, strn, tab[10000], tab2[10000];
    int i, k, j, n, l, tabl;
    char c = 179;
    vector<int> tabs;
    vector<string> stringi;

    while(getline(in, str2)){
        str += str2;
        str += ' ';
    }
    k = 0;
    for(i = 0; i < str.length(); i++){
        if(str[i] != ' ' && str[i] != '.' && str[i] != '\t' && str[i] != ','
           && str[i] != ';' && str[i] != ':' && str[i] != '}' && str[i] != '{'){
            tab[k] += tolower(str[i]);
        }else{
            k++;
        }
        if(str[i] == '.' || str[i] == '\t' || str[i] == ',' || str[i] == ';'
        || str[i] == ':' || str[i] == '}' || str[i] == '{') {
            k--;
        }
    }
    tabl = k;

    k = 0;
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl; j++){
            if(tab[i] == tab[j]){
                k++;
            }
        }
        tabs.push_back(k);
        k = 0;
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tab[j] < tab[j+1]){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    for(i = 0; i < tabl; i++){
        for(j = 0; j < tabl-1; j++){
            if(tabs.at(j) < tabs.at(j+1)){
                n = tabs.at(j);
                tabs.at(j) = tabs.at(j+1);
                tabs.at(j+1) = n;
                strn = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = strn;
            }
        }
    }
    tab2[0] = tab[0];
    for(i = 0; i < tabl; i++){
        if(tab[i] != tab[i+1]){
            tab2[i] = tab[i+1];
        }
    }
    k = 1;
    l++;
    for(i = 0; i < tabl; i++){
        if(!tab2[i].empty()){
            l++;
        }
    }
    cout << "------------------------------------" << endl;
    cout << "|--->TABLE OF MOST COMMON WORDS<---|" << endl;
    cout << "------------------------------------" << endl;
    for(i = 0; i < tabl; i++){
        if(!tab2[i].empty() && k <= 20 ){
            cout << c << k++ << "." << '\t' << c << tab2[i] << '\t' << c << "*" <<
            tabs.at(i+1)
            << '\t'  << c << roundf(((float)tabs.at(i+1)*100/l)*100)/100 << "%" <<
            endl;
        }
    }
    cout << "------------------------------------" << endl ;
    cout << "|----->Dif. strings: " << '\t' << l << "<-------|" << endl ;
    cout << "------------------------------------" << endl;

    return 0;
}