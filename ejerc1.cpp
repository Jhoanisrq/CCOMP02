#include <iostream>

using namespace std;

int main(){
    char f1[23]={"c++ los mejores"};//15   14 1516171819202122 23 
    char f2[]={" y java"};//8
    int x = 3;
    for(char*j1=f1+(sizeof(f1)/sizeof(*f1))-9;j1>f1+2;j1--){
        *(j1+7)=*j1;
    }

    cout<<"{";
    for(char*p=f1;p<f1+(sizeof(f1)/sizeof(*f1))-1;p++){
        cout << *p;
    }//c++ los me los mejores
    cout<<"}"<<endl;

    for(char*j2=f2 ;j2 < f2+(sizeof(f2)/sizeof(*f2))-1; j2++){
        *(f1+x) = *j2;
        x++;
    }

    cout<<"{";
    for(char*p=f1;p<f1+(sizeof(f1)/sizeof(*f1))-1;p++){
        cout << *p;
    }
    cout<<"}"<<endl;

    return 0;
}