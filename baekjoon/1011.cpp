#include<iostream>

using namespace std;


int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        long long int x,y;
        cin>>x>>y;
        long long int b=y-x;
        long long int sq = 0;
        for(long long int i=0;i*i<b;i++){
            sq = i;
        }
        long long int mid = (sq*sq+(sq+1)*(sq+1))/2;
        cout<<"mid : "<<mid<<endl;
        cout<<"sq : "<<sq<<endl;
        cout<<"b : "<<b<<endl;
        if(b<=mid) cout<<2*sq<<endl;
        else cout<<2*sq+1<<endl;
    }
    return 0;
}
