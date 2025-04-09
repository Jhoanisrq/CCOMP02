#include <iostream>

using namespace std;

int main(){
    int B[3][2]={{1,2},{3,4},{5,6}};
    int(*p)[]=B;
    for(int*q=B[0];q<*B+6;q++){
        cout<<*q;
    }
    cout << endl;
    for(int*q=B[0];q<*B+6;q++){
        cout<<*q;
        if(*q%2==0){
            cout << endl;
        }
    }
    cout << endl;
    for(int*q=*B;q<*B+6;q++){
        cout<<*q;
    }
    
    return 0;
}