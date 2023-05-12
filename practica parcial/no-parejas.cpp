#include <iostream>
using namespace std;

bool par(int x){
    return !(x%2);
}

bool inpar(int x){
    return (x%2);
}

bool esCero(int x){
    return !(x);
}

bool pareja(int* x){
    return (*x==*(x+1));
}

void split(int* inicio,int* fin,bool f(int* x)){
    int *r=fin;
    for (int *p=(inicio);p<=r;p++){
        if (f(p)){
            *p=0;
            *(p+1)=0;
            for (int *s=p;s<(r-1);s+=2){
                int tmp1=*s;
                int tmp2=*(s+1);
                *s=*(s+2);
                *(s+1)=*(s+3);
                *(s+2)=tmp1;
                *(s+3)=tmp2;
            }
            r-=2;
            p-=2;
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
    int A[10]={4,3,3,4,3,6,78,9};
    print(A,A+7);
    cout<<endl;
    split(A,A+7,pareja);
    print(A,A+7);

    return 0;
}