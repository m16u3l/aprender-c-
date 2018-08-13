#include <iostream>
#include <cstring>

/*
volver la lista en doblemente enlazada
implementar
-size_t erase (const char*);   //borra todos los elementos que sean iguales a char*
-constructor copia
-operator=();

;n

*/
using namespace std;

class StringLinkedList
{
    struct Node
    {
        size_t len;
        char* s;
        Node* next;
    };

    Node* first;        /*NULL      c   -> numero*/
    Node* last;	/*nullptr c++11 -> clase*/
    size_t count;
public:
    StringLinkedList()
        :first{nullptr}, last{nullptr}, count{0}
    {
    }
    StringLinkedList(const StringLinkedList&) = delete;
    void operator=(const StringLinkedList) = delete;
    void push_back(const char* p)
    {
        auto len = strlen(p);
        auto nn = new char[len+1];
        memcpy(nn, p, len+1);
        Node*/*auto*/ node = new Node{len, nn, nullptr}; //new devuelve puntero
        count++;
        if(first == nullptr){
            first = last = node;
            return;
        }
        last->next = node;
        last = node;
    }
    void show() const
    {
        Node* aux = first;
        while(aux)     //while(aux!=nullptr)
        {
            cout<<aux->s<<endl;
            aux = aux->next;
        }
    }

    ~StringLinkedList()
    {
        Node* node = first;
        while(node != nullptr)
        {
            Node* next = node->next;
            delete []node->s;
            delete node;
            node = next;
        }
    }
};

int main(int argc, char const *argv[])
{
    StringLinkedList s;
    s.push_back("hello");
    s.push_back("world");
    s.push_back("c++");
    s.push_back("rules");

    s.show();

    return 0;
}