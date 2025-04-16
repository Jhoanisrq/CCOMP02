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
    int*pi=*A-1;
    int*pf=*A+(3*3);
    int r=1;
    for(int(*p)[3]=C;p<C+3;p++){
        for(int*q=*p;q<*(p+1);q++,r++){
            *q=r;
            if(r==*pf-1){
                *q=0;
                r=0;
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
        //mover a la izquierda (a/A)
        if(mov=='a'||mov=='A'){
            pc=col-1;
            if(pc>=pi && pc>*fil-1){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más a la izquierda, elija otro moviminto"<<endl;}
        }
        //mover a la derecha(d/D)
        if(mov=='d'||mov=='D'){
            pc=col+1;
            if(pc<=pf && pc<*fil+1){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más a la derecha, elija otro moviminto"<<endl;}
        }
        //mover arriba(w/W)
        if(mov=='w'||mov=='W'){
            pc=col-3;
            if(pc>=pi){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más arriba, elija otro moviminto"<<endl;}
        }
        //mover abajo(s/S)
        if(mov=='s'||mov=='S'){
            pc=col+3;
            if(pc<=pf){
                cambio(pc,col);
            }else{cout<<"NO puede moverse más abajo, elija otro moviminto"<<endl;}
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