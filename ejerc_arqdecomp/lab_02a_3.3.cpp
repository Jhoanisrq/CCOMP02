#include <iostream>
using namespace std;

void suma(int*iA,int*fA,int*iM,int*fM){
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

void resta(int*iA,int*fA,int*iM,int*fM){
    int c=0;
    int s=1;
    invertir(iM,fM);
    suma(iA,fA,iM,fM);
    invertir(iM,fM);
}
void shift(int*iA,int*fA,int*iQ,int*fQ,int* q_1){
    int ini=*iA;
    int temp=0;
    int sus=0;
    for(int*u=iA;u<=fA;u++){
        if(u<=iA+1){
            if(u==iA+1){sus=*u;}
            if(ini==0){*u=0;}
            else if(ini==1){*u=1;}
        }else{
            temp=*u;
            *u=sus;
            sus=temp;
        }
    }
    for(int*q=iQ;q<=fQ;q++){
        temp=*q;
        *q=sus;
        sus=temp;
    }
    *q_1=sus;    
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
    /*ejem01:                               ejem02:
    n=4                                     n=8
    A[]={0,0,0,0};                          A[]={0,0,0,0,0,0,0,0};
    M[]={0,1,1,1}; +7                       M[]={1,1,1,1,0,0,1,0}; -14
    Q[]={1,0,1,0}; -6                       Q[]={0,0,0,0,1,0,0,1}; 9
    */
    int Q_1=0;
    int*q_1=&Q_1;
    int*iA=A+0;
    int*iM=M+0;
    int*iQ=Q+0;
    int*fA=A+n-1;
    int*fM=M+n-1;
    int*fQ=Q+n-1;

    for(int i=n;i>0;i--){
        if(*fQ==0 && Q_1==1){
            suma(iA,fA,iM,fM);
            cout<<endl;
            for(int*a=A;a<=fA;a++){
                cout <<*a;
            }
            cout<<" ";
            for(int*q=Q;q<=fQ;q++){
                cout <<*q;
            }
        }
        else if(*fQ==1 && Q_1==0){
            resta(iA,fA,iM,fM);
            cout<<endl;
            for(int*a=A;a<=fA;a++){
                cout <<*a;
            }
            cout<<" ";
            for(int*q=Q;q<=fQ;q++){
                cout <<*q;
            }
        }
        shift(iA,fA,iQ,fQ,q_1);
        cout<<endl;
        for(int*a=A;a<=fA;a++){
            cout <<*a;
        }
        cout<<" ";
        for(int*q=Q;q<=fQ;q++){
            cout <<*q;
        }
    }
    cout<<endl;
    cout<<"La respuesta en binario complemento 2 es:"<<endl;
    for(int*a=A;a<=fA;a++){
        cout <<*a;
    }
    for(int*q=Q;q<=fQ;q++){
        cout <<*q;
    }
}
