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

template <class T>
void merge(nodo<T>* &H1,nodo<T>* &H2){
    nodo<T>* h1=H1,* h2=H2;
    if (h1->valor <= h2->valor){
        while (h2){
            if (h1->next== 0 || h2->valor < h1->next->valor){
                nodo<T>* tmp=h2->next;
                h2->next=h1->next;
                h1->next=h2;
                h2=tmp;
                h1=h1->next;
            }
            else{
                h1=h1->next;
            }
        }
        H2=h2;
    }
    else{
        while (h1){
            if (h2->next== 0 || h1->valor < h2->next->valor){
                nodo<T>* tmp=h1->next;
                h1->next=h2->next;
                h2->next=h1;
                h1=tmp;
                h2=h2->next;
            }
            else{
                h2=h2->next;
            }
        }
        H1=h1;
    }
}

int main()
{
	LE<int> l1;
    LE<int> l2;
	l1.add(1);
	l1.add(5);
	l1.add(6);
	l2.add(2);
	l2.add(3);
    l2.add(7);

    l1.print();
    l2.print();

    merge(l1.head,l2.head);

    l1.print();
    l2.print();

    l1=LE<int>();
    l2=LE<int>();
	l1.add(1);
	l1.add(5);
	l1.add(6);
	l2.add(2);
	l2.add(3);
    l2.add(7);

    l1.print();
    l2.print();

    merge(l2.head,l1.head);

    l1.print();
    l2.print();

    LE<int> l3;
    LE<int> l4;
	l4.add(1);
	l4.add(5);
	l4.add(6);
	l3.add(2);
	l3.add(3);
    l3.add(7);

    l3.print();
    l4.print();

    merge(l3.head,l4.head);

    l3.print();
    l4.print();

	return 0;
}