#include <iostream>

using namespace std;

template<typename T>
class array_list
{
    T* items;
    size_t cap;
    size_t count;

public:
    array_list(size_t cap = 4)
    :items{new T[cap]}, cap{cap}, cout{0}
    {}
    ~array_list(){}

    void push_back()
    {
        if (items)
        {
            resize();
        }
    }
    
};

int main(int argc, char const *argv[])
{
    array_list<string> p;
    p.push_back("hola");
    p.push_back("mundo");
    p.push_back("today");
    p.push_back("diez");

    for (auto& i : p)
    {
        cout << i << endl;
    }

    for (auto i = p.begin(); i != p.end(); ++i)
    {
        cout << *i << endl;
    }

    return 0;
}