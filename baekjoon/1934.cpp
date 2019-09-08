#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    return (a * b)/gcd(a,b);
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int n,m; cin>>n>>m;
        cout<<lcm(n,m)<<endl;
    }
    return 0;
}