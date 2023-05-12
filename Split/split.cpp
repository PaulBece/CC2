#include <iostream>
using namespace std;

bool par(int x){
    return !(x%2);
}

bool inpar(int x){
    return (x%2);
}

void split(int* inicio,int* fin,bool f(int x)){
    int *r=inicio;
    for (int *p=(inicio);p<=fin;p++){
        if (f(*p)){
            for (int *s=p;s>r;s--){
                int tmp=*s;
                *s=*(s-1);
                *(s-1)=tmp;
            }
            r++;
        }
    }
}

void print(int* inicio,int* fin){
    while (inicio<=fin){
        cout<<*inicio<<" ";
        inicio++;
    }
}

int main(){
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    print(A,A+9);
    cout<<endl;
    split(A,A+9,par);
    print(A,A+9);

    return 0;
}