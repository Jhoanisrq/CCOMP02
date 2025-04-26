#include <iostream>
using namespace std;

int mulmas(int*a,int*b) {
    int result=0;
    int*fin=a+3;
    for (int*i=a;i<fin;i++,b++) {
        result +=(*i)*(*b);
    }
    return result;
}

void MULT(int(*M)[3][3]) {
    int(*A)[3]=*M;
    int(*B)[3]=*(M + 1);
    int(*fin)[3]=*(M + 3);
    int X[3]={};
    int Y[3]={};
    int*x=X;
    int*finx=X+3;
    int*y=Y;
    int*finy=Y+3;
    // Recorrer matriz C
    for (int(*fil)[3] = *(M + 2); fil< fin;fil++) {
        int ub_fil = fil - *(M+2);
        for (int*col=*fil;col<*(fil + 1); col++) {
            int ub_col=col-*fil; 
            for(int(*fb)[3]=B;fb<*(M+2)&&x<finx;fb++){
                for(int*cb=*fb+ub_col;cb<*(fb+3)&&x<finx;cb+=3){
                    *x=*cb;
                    x++;
                }
            }
            x=X;
            for(int(*fa)[3]=A+ub_fil;fa<*(M+1)&&y<finy;fa++){
                for(int*ca=*fa;ca<*(fa+1)&&y<finy;ca++){
                    *y=*ca;
                    y++;
                }
            }
            y=Y;
            *col= mulmas(Y,X);
        }
    }
}
int main(){
    int M[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{9,8,7},{6,5,4},{3,2,1}},{{0,0,0},{0,0,0},{0,0,0}}};
    MULT(M);
    for (int(*mat)[3][3]=M;mat<M+3;mat++){
        cout<<"Matriz:\n";
        for (int(*fila)[3]=*mat;fila<*mat+3;fila++){
            for (int*col=*fila;col<*(fila+1);col++){
                cout<<*col<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}