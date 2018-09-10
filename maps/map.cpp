#include <map>
#include <unordered_map>
#include <tuple>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const tuple<string, string, int>& x)
{
    //1235123
    os << get<0>(x) << " " << get<1>(x) << "(" << get<2>(x) << ")";
    return os;
}

//
int main(int argc, char const *argv[])
{
    //map<clave, valor, less>
    map<int, tuple<string, string, int>> ps;
    ps.insert(pair<int, tuple<string, string, int>> (1028954, tuple<string, string, int>{"juan", "calderon", 1980}));


    //tuple<1,..,n>
    ps.insert(make_pair(2248516, make_tuple("jorge", "cortez", 1978)));
    //el operador[] busca un elemento que por una clave, si ho existe lo crea.
    ps[4529842] = make_tuple("pamela", "alvarez", 1985);

    //iterar
    for(auto& p:ps)
    {
        cout << "key: " << p.first << " value: " << p.second << endl;
    }

    //aca se crea un nuevo objeto pensando que buscamos en un map<>
    auto& q = ps[1234567];
    cout << get<2>(q) << endl;

    //auto r = ps.find(1234567);    //esto lo encuentra
    auto r = ps.find(2248516);
    if (r == ps.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << r->second << endl;
        //cout << (*r).second << endl;
    }

    //---------------------------------------------
    //unordered_map O(1)
    unordered_map<int, tuple<string, string, int>> qs;
    for (auto& p:ps)
    {
        qs.insert(p);
    }
    puts("************************************");
    for(auto& q:qs){
        cout << q.first << " " << q.second << endl;
    }
    return 0;
}