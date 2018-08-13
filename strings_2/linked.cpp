#include <iostream>
#include <cstring>

using namespace std;

class StringDualLinkedList
{
    struct DualNode
    {
        size_t len;
        char* s;
        DualNode* next;
        DualNode* prev;
    };
    DualNode* first = nullptr;
    DualNode* last = nullptr;
    size_t count;
public:
    StringDualLinkedList():first{nullptr},last{nullptr},count{0}
    {
    }

    StringDualLinkedList(const StringDualLinkedList &dualList)
    {
        DualNode* aux = dualList.first;
        DualNode *node = new DualNode{aux->len, aux->s, aux->next, aux->prev};
        if (dualList.first == dualList.last)
        {
            first = last = node;
        }
        else 
        {
            first = last = node;
            while(aux){
                last = aux->next; 
                aux = aux->next;
            }
        }
    }

    //operador igual
    StringDualLinkedList& operator=(const StringDualLinkedList &dualList)
    {
        if(this == &dualList)
        {
            return *this;
        }
        this->~StringDualLinkedList();
        this->count = dualList.count;
        DualNode* aux = dualList.first;
        DualNode *node = new DualNode{aux->len, aux->s, aux->next, aux->prev};
        first = last = node;
        while(aux != nullptr)
        {
            last = aux;
            aux = aux->next;
        }
        return *this;
    }

    void push_back(const char*p){
        auto len = strlen(p);
        auto nn = new char[len+1];
        memcpy(nn,p,len+1);
        //new siempre devuelve puntero
        DualNode *node = new DualNode{len,nn,nullptr,nullptr};
        count++;
        if(first==nullptr)
        {
            first = last = node;
            return;
        }
        last->next=node;
        last=node;
    }

    void push_front(const char* p){
        auto len = strlen(p);
        auto nn = new char[len+1];
        memcpy(nn, p, len+1);

        DualNode *node = new DualNode{len, nn, nullptr,nullptr};
        count++;
        if(first == nullptr)
        {
            first = last = node;
            return;
        }
        node->next = first;
        first->prev = node;
        first = node;
    }

    void show() const {
        DualNode* aux = first;
        while(aux)
        {
            cout<<aux->s<<endl;
            aux=aux->next;
        }
    }
    ~StringDualLinkedList(){
        DualNode* node = first;
        while(node!=nullptr){
            DualNode* next = node->next;
            delete []node->s;
            delete node;
            node = next; 
        }
    }

    size_t erase(const char* word)
    {
        size_t res = 0;
        DualNode* aux = first;
        while(aux != nullptr){
            //cout<<last->s<<endl;
            if(strcmp(first->s, word) == 0)
            {
                first = aux->next;
                aux->next = nullptr;
                aux->prev = nullptr;
                //cout<<first->s<<endl;
                delete []aux->s;
                delete aux;
                res++;
            }
            else
            {
                if (aux != nullptr)
                {
                    cout<<aux->s<<endl;
                    if(strcmp(aux->s, word) == 0)
                    {
                        res++;
                        delete []aux->s;
                        delete aux;
                    }
                    else
                    {
                        if(strcmp(aux->s, word) == 0)
                        {
                            last = aux->next;
                            res++;
                            delete []aux->next;
                            delete aux;
                        }
                    }
                }
            }
            aux=aux->next;
        }
        cout<<res<<endl;
        return res;
    }
};

int main(){
    StringDualLinkedList s;
    s.push_back("world");
    s.push_front("hello");
    s.push_back("c++");
    s.push_front("new");

    StringDualLinkedList p;
    p = s;
    p.erase("c++");
    //s.show();
    //p.show();
}

