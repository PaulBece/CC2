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
struct LEC {
	nodo<T>* head = 0;
    nodo<T>* tail = 0;
	bool find(T v, nodo<T>* &pos) {
		for (nodo<T>* p = head; p && p->valor<=v; pos=p, p = p->next) {
			if (p->valor == v)
				return 1;
            if (p==tail){
                pos=p;
                break;
            }
		}
		return 0;
	}
	void add(T v) {
		nodo<T>* pos=0;
		if (!find(v, pos)) {
			if (pos){
                if (pos == tail) {
                    tail->next = new nodo<T>(v, tail->next);
                    tail = tail->next;
                }
                else
                    pos->next = new nodo<T>(v, pos->next);
            }
			else{
				head = new nodo<T>(v,head);
                if (!head->next){
                    head->next=head;
                    tail=head;
                }
                else
                    tail->next=head;
            }
		}
	}
	bool del(T v) {
        nodo<T>* pos=0;
		bool res=find(v,pos);
        if (res){
            if (pos){
                if (pos->next==tail){
                    nodo<T>* tmp=pos->next;
                    pos->next=tmp->next;
                    tail=pos;
                    delete tmp;
                }
                else{
                    nodo<T>* tmp=pos->next;
                    pos->next=tmp->next;
                    delete tmp;
                }
            }
            else{
                if (head==tail){
                    delete head;
                    head=0,tail=0;
                }
                else{
                    nodo<T>* tmp=head;
                    head=tmp->next;
                    tail->next=head;
                    delete tmp;
                }
            }
        }
        return res;
	}
    void print(){
        std::cout<<"Head->";
        for(nodo<T>* p=head;p;p = p->next){
            std::cout<<p->valor<<"->";
            if (p==tail){
                std::cout<<p->next->valor;
                break;
            }
        }
        std::cout<<std::endl;
    }
    ~LEC(){
        while (head){
            if (head==tail){
                delete head;
                head=0,tail=0;
            }
            else{
                nodo<T>* tmp=head;
                head=tmp->next;
                delete tmp;
            }
        }
    }
};


int main()
{
	LEC<int> l1;
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