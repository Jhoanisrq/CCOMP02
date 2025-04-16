#include <iostream>
using namespace std;

int suma(int*iA,int*fA,int*iM,int*fM){
    int c=0;
    for(int*u=fA;u>=iA;u--){ 
        if(*u+*fM==0){
            if(c==0){
                c=0;
                *u=0;
            }
            else if(c==1){
                c=0;
                *u=1;
            }
            fM--;
        }
        else if(*u+*fM==1){
            if(c==0){
                c=0;
                *u=1;
            }
            else if(c==1){
                c=1;
                *u=0; 
            }
            fM--;
        }
        else if(*u+*fM==2){
            if(c==0){
                c=1;
                *u=0;
            }
            else if(c==1){
                c=1;
                *u=1; 
            }
            fM--;
        }
    }
    return c;
}
void invertir(int*iM,int*fM){
    int c=0;
    int s=1;
    for(int*u=fM;u>=iM;u--){ 
        if(*u==0){              // u=1
            if(s==1){
                *u=0;
                c=1;
                s=0;
            }
            else if(s==0){  
                if(c==0){
                    *u=1;
                    c=0;
                }
                else if(c==1){
                    *u=0;
                    c=1;
                }
            }
        }
        else if(*u==1){         //u=0
            if(s==1){
                *u=1;
                c=0;
                s=0;
            }
            else if(s==0){  
                if(c==0){
                    *u=0;
                    c=0;
                }
                else if(c==1){
                    *u=1;
                    c=0;
                }
            }
        }
    }
}

void resta(int*iA,int*fA,int*iM,int*fM,int*q_0){
    invertir(iM,fM);
    *q_0=suma(iA,fA,iM,fM);
    invertir(iM,fM);
}
void left_shift(int*iA,int*fA,int*iQ,int*fQ){
    int ini=*fQ;
    int temp=0;
    int atr=0;
    for(int*u=fQ;u>=iQ;u--){
        if(u>=fQ-1){
            if(u==fQ-1){atr=*u;}
            if(ini==0){*u=0;}
            else if(ini==1){*u=1;}
        }else{
            temp=atr;
            atr=*u;
            *u=temp;
        }
    }
    for(int*q=fA;q>=iA;q--){
        temp=atr;
        atr=*q;
        *q=temp;
    }    
}
int main(){
    int n=4;
    cout<<"colocar el tamaño en n bits:";
    cin>>n;
    int M[n]={};
    int A[n]={};
    int Q[n]={};
    for (int i=0;i<n;i++){
        *(A+i)=0;
    }
    cout << "colocar el Multiplicando(M) en binario compemento2 uno por uno: ";
    for (int i=0;i<n;i++){
        cin>>*(M+i);
    }
    cout << "colocar el Multiplicador(Q) en binario compemento2 uno por uno: ";
    for (int i=0;i<n;i++){
        cin>>*(Q+i);
    }
    /*ejem01:              Q/M              ejem02:
    n=4                                     n=8
    A[]={0,0,0,0};                          A[]={0,0,0,0,0,0,0,0};
    M[]={0,0,1,1}; 3                        M[]={1,1,1,1,0,0,1,0}; -14
    Q[]={0,1,1,1}; 7                        Q[]={0,0,0,0,1,0,0,1}; 9
    */
    int Q_0=0;
    int*q_0=&Q_0;
    int*iA=A+0;
    int*iM=M+0;
    int*iQ=Q+0;
    int*fA=A+n-1;
    int*fM=M+n-1;
    int*fQ=Q+n-1;

    for(int i=n;i>0;i--){
        left_shift(iA,fA,iQ,fQ);
        cout<<endl;
        resta(iA,fA,iM,fM,q_0);
        *fQ=Q_0;
        cout<<"left shift"<<endl;
        for(int*a=A;a<=fA;a++){
            cout <<*a;
        }
        cout<<" ";
        for(int*q=Q;q<=fQ;q++){
            cout <<*q;
        }
        if(Q_0==0){
            suma(iA,fA,iM,fM);
            cout<<" Se restaura A"<<endl;
            for(int*a=A;a<=fA;a++){
                cout <<*a;
            }
            cout<<" ";
            for(int*q=Q;q<=fQ;q++){
                cout <<*q;
            }
        }
        if(Q_0==1){
            cout<<" A permanece"<<endl;
            for(int*a=A;a<=fA;a++){
                cout <<*a;
            }
            cout<<" ";
            for(int*q=Q;q<=fQ;q++){
                cout <<*q;
            }
        }
    }
    cout<<endl;
    cout<<"La respuesta en el Cociente: ";
    for(int*q=Q;q<=fQ;q++){
        cout <<*q;
    }
    cout<<"\nLa respuesta en el Residuo es: ";
    for(int*a=A;a<=fA;a++){
        cout <<*a;
    }
}
