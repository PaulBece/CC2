#include <iostream>

using namespace std;

template <class T>
class Iterator
{
    T* it;
public:
    // T* it;

    void operator =(T* valor)
    {
        it = valor;
    }

    void operator =(T valor)
    {
        it->valor = valor.valor;
    }

    /*void operator +=(T valor)
    {
        it.add(T);
    }

    void operator -=(T valor)
    {
        *it = valor;
    }*/

    T* operator++(int)
    {
        it = it->next;
        return it;
    }

    T operator*()
    {
        return it->valor;
    }

    bool operator<=(T* otro)
    {
        return it->valor <= otro->valor;
    }

    bool operator!=(T* otro)
    {
        return it != otro;
    }

    friend istream& operator >> (istream& input, Iterator D)
    {
        input >> (D.it->valor);
        return input;
    }

    friend ostream& operator << (ostream& output, Iterator D)
    {
        output << (D.it->valor);
        return output;
    }

};

template <class T>
class nodo
{
public:
    T valor;
    nodo* next;
    nodo(T v, nodo* n = nullptr)
    {
        valor = v;
        next = n;
    }
};

template <class T, class I>
class LE
{
    nodo<T>* head = nullptr;

public:
    typedef I it_vector;
    void print() {
        cout << "Head->";
        for (nodo <T>* p = head; p; p = p->next)
            cout << p->valor << "->";
        cout << "NULL" << endl;
    }
    bool find(T v, nodo<T>*& pos) {
        bool encontrado = false;
        pos = nullptr;

        for (nodo<T>* p = head; p && p->valor <= v; p = p->next)
        {
            if (p->valor == v)
            {
                encontrado = true;
                break;
            }
            pos = p;
        }
        return encontrado;
    }
    void add(T v) {
        nodo<T>* pos_ant;
        if (!find(v, pos_ant))
        {
            if (pos_ant)
                pos_ant->next = new nodo<T>(v, pos_ant->next);
            else
                head = new nodo<T>(v, head);
        }
    }
    void del(T v) {
        nodo<T>* pos_ant, * pos_del;
        if (find(v, pos_ant))
        {
            if (pos_ant)
            {
                pos_del = pos_ant->next;
                pos_ant->next = pos_del->next; //pos_ant->next = pos_ant->next->next;
                delete pos_del;
            }
            else
            {
                pos_del = head;
                head = pos_del->next; //head = head->next;
                delete pos_del;
            }
        }
    }
    nodo<T>* begin() {
        return head;
    }
    nodo<T>* end() {
        return 0;
    }
    ~LE() {
        /* cout<<"Destruyendo lista..."<<endl;
        while(head)
        {
        cout<<head->valor<<" ";
        del(head->valor);
        }
        cout<<endl<<"Lista destruida";*/
        while (head)
            del(head->valor);
    }
};

int main() {
    LE<int, Iterator<nodo<int>>> lista1;
    LE<int, Iterator<nodo<int>>>::it_vector It;

    for (int i = 0; i < 10; i++) {
        lista1.add(i);
    }

    int x = 100;
    for (It = lista1.begin(); It != 0; It++)
    {
        It = x;
        x += 100;
    }

    for (It = lista1.begin(); It != 0; It++)
    {
        cout << It << endl;
    }

    cout << "-----------------" << endl;

    for (It = lista1.begin(); It != 0; It++)
    {
        cout << "Ingrese un numero a la lista: ";
        cin >> It;
    }

    for (It = lista1.begin(); It != 0; It++)
    {
        cout << It << endl;
    }

}