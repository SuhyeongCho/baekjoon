#include<iostream>

using namespace std;
int data[10];
int main(){
    int T; cin>>T;
    data[0] = 1;
    data[1] = 2;
    data[2] = 4;
    
    for(int i=3;i<10;i++){
        data[i] = data[i-1] + data[i-2] + data[i-3];
    }
    
    for(int t=0;t<T;t++){
        int a; cin>>a;
        cout<<data[a-1]<<endl;
    }
}
