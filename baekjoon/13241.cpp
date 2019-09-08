#include <iostream>

using namespace std;

long long int gcd(long long int a,long long int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

long long int lcm(long long int a,long long int b){
    return (a * b)/gcd(a,b);
}
int main(){
    long long int n,m; cin>>n>>m;
    cout<<lcm(n,m)<<endl;
    return 0;
}