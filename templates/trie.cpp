#include <iostream>

using namespace std;

//arbol de prefijos
int main(int argc, char const *argv[])
{
    TRIE<string> x;

    x.add("dog", "perro");
    x.add("cat", "gato");
    x.add("day", "dia");
    x.add("car", "carro");
    x.add("doctor", "doctor");
    x.add("carrot", "zanahoria");

    cout << x["car"] << endl;//carro
    cout << x["day"] << endl;//dia
    cout << x["perro"] << endl;//-1
    return 0;
}