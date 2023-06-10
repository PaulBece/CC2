#include <iostream>

template <typename T>
struct nodo {
	T valor;
	nodo<T>* next;
	nodo(T v, nodo<T>* n = 0) {
		valor = v;
		next = n;
	}
};

template<class T>
struct LE {
	nodo<T>* head = 0;
	bool find(T v, nodo<T>* &pos) {
		for (nodo<T>* p = head; p && p->valor<=v; pos=p, p = p->next) {
			if (p->valor == v) {
				return 1;
			}
		}
		return 0;
	}
	void add(T v) {
		nodo<T>* pos=0;
		if (!find(v, pos)) {
			if (pos)
				pos->next = new nodo<T>(v, pos->next);
			else
				head = new nodo<T>(v,head);
		}
	}
	bool del(T v) {
        nodo<T>* pos=0;
		bool res=find(v,pos);
        if (res){
            if (pos){
                nodo<T>* tmp=pos->next;
                pos->next=tmp->next;
                delete tmp;
            }
            else{
                nodo<T>* tmp=head;
                head=tmp->next;
                delete tmp;
            }
        }
        return res;
	}
    void print(){
        std::cout<<"Head->";
        for(nodo<T>* p=head;p;p = p->next)
            std::cout<<p->valor<<"->";
        std::cout<<"NULL"<<std::endl;
    }
    ~LE(){
        while (head){
            nodo<T>* tmp=head;
            head=tmp->next;
            delete tmp;
        }
    }
};


template <typename T>
struct cola {
	nodo<T>* head = 0;
	nodo<T>* tail = 0;
	void add(T valor) {
		if (!head) {
			head = new nodo<T>(valor);
			tail = head;
		}
		else {
			(*tail).next = new nodo<T>(valor);
			tail = (*tail).next;
		}
	}
	bool pop(T& valor) {
		bool aux = 1;
		if (!head) {
			aux = 0;
		}
		else {
			nodo<T>* tmp = head;
			valor = (*head).valor;
			head = (*head).next;
			delete tmp;
		}
		return aux;
	}
};


int main()
{
	LE<int> l1;
	l1.add(1);
	l1.add(2);
	l1.add(3);
	l1.add(4);
	l1.add(5);
    l1.add(1);
	l1.add(2);
	l1.add(3);
	l1.add(4);
	l1.add(5);
    l1.add(6);

    l1.print();

    l1.del(2);
    l1.del(15);
    l1.del(2);
    l1.del(5);
    l1.del(1);

    l1.print();

    l1.add(0);
    l1.add(9);

    l1.print();

	return 0;
}