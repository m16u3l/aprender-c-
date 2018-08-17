#include <iostream>

using namespace std;


string join(const string& , const string& cad)
{
    return cad;
}

void internal_join(const string& aux, const string& b)
{
    aux + b;
}

template<typename...ARGS>
void internal_join(const string& aux, const string sep, const ARGS&...args)
{
    aux + sep + internal_join(args...); 
}

template<typename...ARGS>
string join(const string& sep, 
            const string& w,
            const ARGS&...args)
{
    string aux;
    internal_join(aux, sep, args...);
    return aux;
}

int main()
{
    string p = join(",", "Juan", "Pedro", "Jose", "Maria");
    cout << p << endl;

    return 0;
}
