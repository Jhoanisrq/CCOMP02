#include <iostream>
using namespace std;

void cambio(int*p,int*u){
    int temp=*p;
    *p=*u;
    *u=temp;
}
int main(){
    int A[][3]={{1,8,5},{7,2,0},{3,4,6}};
    int C[][3]={{},{},{}};
    int(*fil)[3]=A;
    int*col=*A;
    int*pc=*A;
    int*ini=*A-1;
    int*fin=*A+(3*3);
    int r=1;
    for(int(*p)[3]=C;p<C+3;p++){
        for(int*q=*p;q<*(p+1);q++,r++){
            *q=r;
            if(r==*fin-1){
                *q=0;
            }
        }
    }
    cout<<"Ordene la tabla de 3x3 tu eres 0: "<<endl;
    //Imprime y me da la ubicación de 0
    for(int(*p)[3]=A;p<A+3;p++){
        for(int*q=*p;q<*(p+1);q++){
            cout<<*q<<"\t";
            if(*q==0){
                col=q;
                fil=p;
            }
        }
        cout<<endl;
    }
    int i=1;
    char mov;
    while(i !=0){
        cout<<"Moverte a izq(a/A), derecha(d/D), arriba(w/W), abajo(s/S): ";
        cin>>mov;

        int ubicfilcol = *fil-col;

        //mover a la izquierda (a/A)
        if(mov=='a'||mov=='A'){
            if (ubicfilcol > 0) {
                pc = col - 1;
                cambio(pc, col);
            }else{cout<<"NO puede moverse más a la izquierda"<<endl;}
        }
        //mover a la derecha(d/D)
        if(mov=='d'||mov=='D'){
            if(ubicfilcol < 2){
                pc=col+1;
                cambio(pc,col);
            }else{cout<<"NO puede moverse más a la derecha"<<endl;}
        }
        //mover arriba(w/W)
        if(mov=='w'||mov=='W'){
            pc=col-3;
            if(pc>ini){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más arriba"<<endl;}
        }
        //mover abajo(s/S)
        if(mov=='s'||mov=='S'){
            pc=col+3;
            if(pc<fin){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más abajo"<<endl;}
        }
        for(int(*p)[3]=A;p<A+3;p++){
            for(int*q=*p;q<*(p+1);q++){
                cout<<*q<<"\t";
                if(*q==0){
                    col=q;
                    fil=p;
                }
            }
            cout<<endl;
        }
        if(A==C){
            cout<<"TERMINO";
            i--;
        }
    }
    /*
    preguntar para donde se va a mover0
    verificar si ya esta ordenado
    */  
    return 0;
}