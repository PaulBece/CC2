#include <iostream>
#include "Cola.h"

using namespace std;



int main()
{
    Cola cola1;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cola1.push(1);
    cola1.push(2);
    cola1.push(3);
    cola1.push(4);
    cola1.push(5);
    cola1.push(6);
    cola1.push(7);
    cola1.push(8);
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cola1.push(9);
    cola1.push(10);
    cola1.push(11);
    cola1.push(12);
    cola1.push(13);
    cola1.push(14);
    cola1.push(15);
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    cout << cola1.pop() << endl;
    
    return 0;
}