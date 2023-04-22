#include "Cola.h"
#include <iostream>

void Cola::mtail() {
	tail++;
	if (tail == fin)
		tail = arr;
	
}

void Cola::mhead() {
	head++;
	if (head == fin)
		head = arr;
}
void Cola::push(int valor) {
	if (!tail) {
		head = arr;
		tail = arr;
		*tail = valor;
	}
	else {
		mtail();
		if (tail == head) {
			tail--;
			std::cout << "Cola llena" << std::endl;
		}
		else
			*tail = valor;
	}
	
}

int Cola::pop() {
	if (head){
		int tmp = *head;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
			return tmp;
		}
		else {
			mhead();
			return tmp;
		}
	}
	else {
		std::cout << "Cola vacia ";
		return 0;
	}
}