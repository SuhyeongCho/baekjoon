#include <iostream>

using namespace std;

long long int gcd(long long int a,long long int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    long long int n,m; cin>>n>>m;
    
    long long int gcdValue = gcd(n,m);

    for(int i=0;i<gcdValue;i++){
        cout<<1;
    }
    cout<<endl;
    return 0;
}