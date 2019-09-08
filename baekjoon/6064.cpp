#include<iostream>

using namespace std;

void func(){
    int M,N,x,y;
    cin>>M>>N>>x>>y;
    
    if(M>N){
        swap(M,N);
        swap(x,y);
    }
    
    int diff = N-M;
    int a=x,b=x,pos=x;
    for(int i=0;i<N;i++){
        if(a==x&&b==y){
            cout<<pos<<endl;
            return;
        }
        pos += M;
        b = b - diff;
        if(b<=0) b+=N;
    }
    cout<<-1<<endl;
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        func();
    }
}
