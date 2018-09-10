#include <iostream>
#include <unordered_map>
#include <memory>
#include <functional>

using namespace std;

void f(int n)
{
    cout << n*n << endl;
}

template<typename T, typename Q, typename R>
void ins(T& m, Q q, R r)
{
    m.insert(make_pair(make_unique<Q>(q), r));
    //m.insert(make_pair(make_unique<Q>(new Q{q})));
    //m[make_unique<Q>(new)(q)] = r;
}

using up = unique_ptr<int>;
//si la clave no es de tipo primitivo o un string
struct up_hash
{
    size_t operator()(const up& n) const
    {
        return *n;
    }
};

struct up_eq
{
    bool operator()(const up& a, const up& b) const
    {
        return *a == *b;
    }
};

//esto recibe una funcion
using mfunc = function<void(int)>;

int main(int argc, char const *argv[])
{
    //unordered_map<unique_ptr<int>, void(*)(int)> ms;
    unordered_map<up, mfunc/*void(*)(int)*/, up_hash, up_eq> ms;

    ins(ms, 64,[](int p){
        cout << p+1 << endl;
    });

    ins(ms, 125,f);
    ms[make_unique<int>(64)](12);


    //
    int m = 200;
    ins(ms, 148, [&m](int n){
        cout << m+n << endl;
    });

    ms[make_unique<int>(148)](22);

    ms[make_unique<int>(64)](122);

    return 0;
}