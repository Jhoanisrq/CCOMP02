#include <iostream>
using namespace std;

//Lo unico que se tiene que cambiar es A

void merge(int*x,int*y){
    int temp= *x;
    *x = *y;
    *y = temp;
}
int main(){
    int A[]={2,8,10,12,24,3,7,15,19,25};
    int *p=A;
    int *q=A+((sizeof(A)/sizeof(*A))/2);
    int *fin = p+(q-p)*2;

    for(int*i=A ; i < fin ;i++){
        if(*q<*i){
            merge(i,q);
            i=p;
            p++;
        }
        else if(i == p+(q-p)){
            i=A;
            p=A;
            if(q<fin){
                q++;
            }
        }
    }

    for(int*j=A ; j <= fin ;j++){
        cout<<*j<<" ";
    }
    return 0;
}