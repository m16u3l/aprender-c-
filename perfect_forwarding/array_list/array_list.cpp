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
    :items{new T[cap]}, cap{cap}, count{0}
    {}

    ~array_list()
    {
        delete[] items;
    }

    template<typename U>
    void push_back(U&& item)
    {
        resize();
        items[count++] = forward<U>(item);
    }

    void resize()
    {
        if (cap != count)
        {
            return;
        }
        size_t ncap = cap * 2;
        T* aux = new T[ncap];
        for (auto i = 0U; i < count; i++)
        {
            aux[i] = move(items[i]);
        }
        delete[] items;
        items = aux;
        cap = ncap;
    }

    template<class  U>
    void emplace_back(U&& x)
    {
        resize();
        items[count++] = T{forward<U>(x)};
    }
};

int main(int argc, char const *argv[])
{
    array_list<string> s;
    s.push_back("hola");
    s.push_back("mundo");
    s.push_back("hello");
    s.push_back("diez");

    //copia
    string p = "agosto";
    s.push_back(p);

    //
    //s.emplace_back("Septiembre");

    //cout << s[2] << "\n";
    return 0;
}