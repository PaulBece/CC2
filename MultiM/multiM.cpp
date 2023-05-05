#include <iostream>
using namespace std;

void multi(int(*A)[3][3]) {
    for (int* p1 = **A, * p2 = **(A + 1), * p3 = **(A + 2); p1 < **(A + 1); p2 ++,p3++) {
        if (p2 == *(*(A + 1) + 1)) 
            p2 -= 3, p1 += 3;
        *p3 = (*p1) * (*p2) + *(p1 + 1) * *(p2 + 3) + *(p1 + 2) * *(p2 + 6);}}

void print(int(*A)[3][3]) {
    for (int i =0; i < 27; i++){
        cout << *(**A+i) << " ";
        if (i%3==2)
            cout<<endl;
        if (i%9==8)
            cout<<endl;
    }
}

int main()
{
    int A[3][3][3] = { {{1,3,5},{7,9,11},{13,15,17}},{{2,4,6},{8,10,12},{14,16,18}},{{0,0,0},{0,0,0},{0,0,0}} };
    multi(A);
    print(A);

    return 0;
}