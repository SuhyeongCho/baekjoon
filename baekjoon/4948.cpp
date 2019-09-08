#include<iostream>
using namespace std;

bool isPrime(int num){
    if(num < 1) return 0;
    for(int i=2; i*i <= num; i++){
        if(num % i==0) return 0;
    }
    return 1;
}

int main(){
    int n; cin>>n;
    while(n){
        int count = 0;
        for(int i=n+1;i<=2*n;i++){
            if(isPrime(i)) count++;
        }
        cout<<count<<'\n';
        cin>>n;
    }
}
