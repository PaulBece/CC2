class Cola {
	int arr[10];
	int* head = nullptr;
	int* tail = nullptr;
	int* fin = arr + 10;
	void mtail();
	void mhead();
public:
	void push(int);
	int pop();
};