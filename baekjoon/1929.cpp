#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int M,N;
int main(){
    cin>>M>>N;
    for(int i = M; i <= N; i++) {
        if(isPrime(i)) printf("%d\n",i);
    }
    return 0;
}

