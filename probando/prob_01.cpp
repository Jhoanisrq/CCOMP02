#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

void float_a_IEEE754_ver(float num){
    union {
        float num_ingres;
        uint32_t bits;
    } 
    data;
    data.num_ingres = num;

    bitset<32> binary(data.bits);

    cout<<"Número decimal: "<<num<<endl;
    cout<<"Binario IEEE 754: "<< binary <<endl;
}
void float_a_IEEE754(float num,int*sig,int*expi,int*signi) {
    union {
        float num_ingres;
        uint32_t bits;
    } 
    data;
    data.num_ingres = num;

    bitset<32> binary(data.bits);

    string signo = binary.to_string().substr(0, 1);
    string exponente = binary.to_string().substr(1, 8);
    string significando = binary.to_string().substr(9, 23);

    cout<<"Número decimal: "<<num<<endl;
    cout<<"Binario IEEE 754: "<< binary <<endl;

    *sig=signo[0] - '0';
    for (int j = 0; j < 8; ++j) {
        *(expi + j) = exponente[j] - '0';
    }
    signi[0] = 1;
    for (int j = 0; j < 23 ; ++j) {
        signi[j+1] = significando[j] - '0';
    }

}
int sig_xor(int* sig1,int* sig2){
    if(*sig1==*sig2){
        return 0;
    }else {
        return 1;
    }
}
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
    *q_0 = suma(iA,fA,iM,fM);
    invertir(iM,fM);
}

void left_shift(int* Ai, int* Af, int* Qi, int* Qf) {
    for (int i = 23; i > 0; --i) {
        Ai[i] = Ai[i - 1];
    }
    Ai[0] = Qi[0];

    for (int i = 23; i > 0; --i) {
        Qi[i] = Qi[i - 1];
    }
    Qi[0] = 0;
}
void normalizar(int* A, int* Ai, int* Af, int* expi, int* expf) {
    while (A[0] == 0) {
        for (int i = 0; i < 24; ++i) {
            A[i] = A[i + 1];
        }
        A[23] = 0;

        int one[8] = {0,0,0,0,0,0,0,1};
        int* onei = one;
        int* onef = one + 7;
        int dummy = 0;
        resta(expi, expf, onei, onef, &dummy); // exponente--
    }
}
void redondear(int* A) {
    if (A[24] == 1) { // guard bit
        int carry = 1;
        for (int i = 23; i >= 0 && carry; --i) {
            int sum = A[i] + carry;
            A[i] = sum % 2;
            carry = sum / 2;
        }
    }
}
int main() {
    float num01;
    float num02;
    int bias[8]={0,1,1,1,1,1,1,1}; //127
    int*biasi=bias;
    int*biasf=bias+7;
    int Q_0=0;
    int*q_0=&Q_0;
    int carry=0; 
    int*car=&carry;
    int ExpUnderf[8]={0,0,0,0,0,0,0,0};
    int ExpOverf[8]={1,1,1,1,1,1,1,1};
    
    int A[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int*Ai=A;
    int*Af=A+23;

    int Sig1;
    int Exp1[8]={};
    int Sign1[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int Sig2;
    int Exp2[8]={};
    int Sign2[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int*sig1=&Sig1;
    int*sig2=&Sig2;
    
    int*exp1i=Exp1;
    int*exp1f=Exp1+7;
    int*exp2i=Exp2;
    int*exp2f=Exp2+7;

    int*sign1i=Sign1;
    int*sign2i=Sign2;
    int*sign1f=Sign1+23;
    int*sign2f=Sign2+23;
    
    cout<<"Ingrese 2 números decimales, de tal forma que x/y resulte en una respuesta "<<endl;
    cout<<"Ingresa un número decimal como 3.6(x): ";
    cin>>num01;
    cout<<"Ingresa otro número decimal como 1.2(y): ";
    cin>>num02;
    cout<<endl;
    float_a_IEEE754(num01,sig1,exp1i,sign1i);
    float_a_IEEE754(num02,sig2,exp2i,sign2i);
    cout<<endl;

    int signoR=sig_xor(sig1,sig2);

    float mult=num01*num02; //x*y
    cout<<"La multiplicaion de los numeros: "<<mult<<endl;
    float_a_IEEE754_ver(mult);
    cout<<endl;

    cout<<"El resultado es: "<<num01/num02<<endl;
    if (num01==0.0 && num02==0.0){
        cout<<"NaN";
    }
    else if (num01==0.0){
        if(signoR==0){cout<<"0";}
        if(signoR==1){cout<<"-0";}
    }
    else if(num02==0.0){
        if(signoR==0){cout<<"+∞ infinito";}
        if(signoR==1){cout<<"-∞ infinito";}
    }else{//restar exponentes + bias, todo se guarda en Exp1
        resta(exp1i,exp1f,exp2i,exp2f,car);
        suma(exp1i,exp1f,biasi,biasf);

        bool esOverflow = true;
        bool esUnderflow = true;
        for (int i = 0; i < 8; i++) {
            if (Exp1[i] != ExpOverf[i]) esOverflow = false;
            if (Exp1[i] != ExpUnderf[i]) esUnderflow = false;
        }

        if(esOverflow){ cout<<"Se a detectado Overflow"; }
        else if(esUnderflow){ cout<<"Se a detectado Underflow"; }
        else{//significandos Q/M  sign1/sign2
            int cociente[25] = {}; // 24 bits + 1 extra para redondeo
            int* Qi = cociente;
            int* Qf = cociente + 24;

            for (int i = 0; i < 24; ++i) {
                // Desplaza antes de restar
                left_shift(Ai, Af, Qi, Qf);
                resta(Ai, Af, sign2i, sign2f, q_0);
            
                if (Q_0 == 0) {
                    // resta fue negativa, restauramos A
                    suma(Ai, Af, sign2i, sign2f);
                    Qi[0] = 0;
                } else {
                    Qi[0] = 1;
                }
            }

            // Normalizamos y redondeamos el cociente
            normalizar(cociente, cociente, cociente + 23, exp1i, exp1f);
            redondear(cociente);

            // Mostramos resultado
            cout << signoR << " ";
            for (int* i = Exp1; i <= exp1f; i++) cout << *i;
            cout << " ";
            for (int i = 0; i < 23; ++i) cout << cociente[i];
        }
    }
    return 0;
}
