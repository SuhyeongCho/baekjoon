#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int a,b;
        cin>>a>>b;
        while(a > 1){
            int x = b/a+1;
            a = a*x-b;
            b = b*x;

            int gcdValue = gcd(a,b);
            a /= gcdValue;
            b /= gcdValue;
        }
        cout<<b<<endl;
    }
    return 0;
}