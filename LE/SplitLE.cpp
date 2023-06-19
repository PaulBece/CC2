#include <iostream>

template <class T>
struct nodo
{
    T valor;
    nodo* next;
    nodo(T v,nodo* n = 0) {
        valor = v;
        next = n;
    }
};

template<class T>
struct LE {
    nodo<T>* head = 0;
    bool find(T v, nodo<T>*& pos) {
        for (nodo<T>* p = head; p && p->valor <= v; pos = p, p = p->next) {
            if (p->valor == v) {
                return 1;
            }
        }
        return 0;
    }
    void add(T v) {
        nodo<T>* pos = 0;
        if (!find(v, pos)) {
            if (pos)
                pos->next = new nodo<T>(v, pos->next);
            else
                head = new nodo<T>(v, head);
        }
    }
    bool del(T v) {
        nodo<T>* pos = 0;
        bool res = find(v, pos);
        if (res) {
            if (pos) {
                nodo<T>* tmp = pos->next;
                pos->next = tmp->next;
                delete tmp;
            }
            else {
                nodo<T>* tmp = head;
                head = tmp->next;
                delete tmp;
            }
        }
        return res;
    }
    void print() {
        std::cout << "Head->";
        for (nodo<T>* p = head; p; p = p->next)
            std::cout << p->valor << "->";
        std::cout << "NULL" << std::endl;
    }
    ~LE() {
        while (head) {
            nodo<T>* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
};

template <class T>
struct par {
    bool operator()(T a) {
        return !(a % 2);
    }
};

template <class T>
struct impar {
    bool operator()(T a) {
        return (a % 2);
    }
};

template <class T, class G>
void split(nodo<T>* &h1, nodo<T>* &h2, G op) {
    nodo<T>* ant=0, * p=h1, * q=h2;
    while (p) {
        if (op(p->valor)) {
            ant = p;
            p = p->next;
        }
        else {
            if (p == h1)
                    h1 = p->next;
            if (!q) {
                h2 = p;
                q = h2;}
            else {
                q->next = p;
                q = q->next;}
            p = p->next;
            if (ant)
                ant->next=p;
        }
    }
    q->next = 0;
}

int main()
{
    LE<int> l1;
    LE<int> l2;

    l1.add(1);
    l1.add(3);
    l1.add(5);
    l1.add(7);
    l1.add(8);
    l1.add(9);
    l1.add(10);
    l1.print();
    l2.print();
    std::cout<<"------------------\n";
    split<int,par<int>>(l1.head, l2.head, par<int>());
    l1.print();
    l2.print();
    
    return 0;
}