#include <iostream>
#include <cstring>

using namespace std;

constexpr size_t MAXSTR = 16;

class str
{
private:
    char* s;
    size_t len;
    char sso[MAXSTR];

public:
    str(const char* s = "")
        :len(strlen(s))
    {
        if (len < MAXSTR)
        {
            memcpy(sso, s, len+1);
        } else {
            this->s = new char[len+1];
            memcpy(this->s,s,len+1);
        }
        //cout<<len<<endl;
    }

    str(const str& src)
        :len{src.len}
    {
        if(len<MAXSTR)
        {
            memcpy(sso,src.sso,len+1);
            return;
        }
        s = new char[len+1];
        memcpy(s, src.s, len+1);
    }


    ~str() //siempre publico
    {
        if(len >= MAXSTR)
        {
            delete[]s;
        }
    }

    const char* data() const
    {
        return len<MAXSTR?sso:s;
    }

    void show(){
        cout<<data()<<endl;
    }


    str substr(size_t index, size_t size) 
    {
        return res;
    }


    str(const str& str, size_t index, size_t size)
        :len{size}
    {
        if(len < index)
        {
            memcpy(this->s, "", 2);
            return;
        }
    }
};




int main(int argc, char const *argv[])
{
    str x = "Maria Juana";
    x.substr(6,5);
    x.show();
    return 0;
}

//examen 28 de julio 9-12