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
        }
        else {
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

    str& operator=(const str& src)
    {
        if(this == &src)
        {
            return *this;
        } 
        this->~str();
        len = src.len;
        if(len<MAXSTR)
        {
            memcpy(sso,src.sso,len+1);
        }
        else
        {
            s = new char[len+1];
            memcpy(s,src.s,len+1);
        }
        return *this;
    }

    const char* data() const
    {
        return len<MAXSTR?sso:s;
    }

    void show(){
        cout<<data()<<endl;
    }

    bool operator==(const str& src) const
    {
        if(this == &src)
        {
            return true;
        }
        if(len != src.len)
        {
            return false;
        }
        return memcmp(data(),src.data(),len) == 0;
    }

    bool operator==(const char* s) const
    {
        return strcmp(data(), s) == 0;
    }

    str operator+(const str& src)
    {
        /*size_t*/auto nlen = len + src.len;
        str aux;
        if(nlen < MAXSTR)
        {
            memcpy(aux.sso, sso, len);
            memcpy(aux.sso + len, src.sso, src.len+1);
        }
        else
        {
            aux.s = new char[nlen+1];
            memcpy(aux.s, data(), len);
            memcpy(aux.s+len, src.data(), src.len+1);
        }
        aux.len=nlen;
        return aux;
    }

    str operator+=(const str& src)
    {
        auto nlen = len + src.len;
        if(nlen<MAXSTR)
        {
            memcpy(sso+len, src.sso, src.len+1);
        }
        else
        {
            char* p = new char[nlen+1];
            memcpy(p, data(), len);
            memcpy(p+len, src.data(), src.len+1);
            this->s = p;
            this->~str();
        }
        len = nlen;
        return *this;
    }

    str substr(size_t index, size_t size) const
    {
        str p{""};
        if(this->len < index)
        {
            this->~str();
        }
        else
        {
            if(false){
            }
            this->s* = index;
            char* p = new char[size+1];
            memcpy(p,this->data(), size);
        }
        return p;
    }

};


int main(int argc, char const *argv[])
{
    /*cds
    str x;
    str y{"hello world"};
    str z{"Juan Carlos de Jesus Rodriguez"};

    cout<<y.data()<<endl;

    str a = y;
    str b = z;
    cout<<a.data()<<endl;
    cout<<b.data()<<endl;

    str s = "hola mundo";
    str w = "hello";

    w = s;

    if(w == "hello"){
        cout<<"iguales"<<endl;
    }else{
        cout<<"diferentes"<<endl;
    }
    
    w.show();

    */
    str h = "hello";
    str w = "world";
    str z = h + " " + w;
    //z.show();

    str x = "Maria Juan";
    x.substr(6,5);
    x.show();


    return 0;
}

//examen 28 de julio 9-12