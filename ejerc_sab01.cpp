#include <iostream>

using namespace std;

//Lo unico que se tiene que cambiar es A y q

void merge(int*x,int*y){
    int temp= *x;
    *x = *y;
    *y = temp;
}

int main(){
    int A[]={2,8,10,24,3,7,15,25};
    int *p=A;
    int *q=A+4;
    int *fin = p+(q-p)*2-1;

    for(int*i=A ; i <= fin ;i++){
        if(*q<*i){
            merge(i,q);
            i=p;
            p++;
        }
        else if(i == p+(q-p)){
            i=A;
            p=A;
            if(q <= fin){
                if(q==fin){
                    i = fin;
                    q = fin-(q-p)/2-1;
                }
                q++;
            }
        }
    }

    for(int*j=A ; j <= fin ;j++){
        cout<<*j<<" ";
    }
    return 0;
}