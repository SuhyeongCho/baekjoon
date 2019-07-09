#include<iostream>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return 0;
    
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int M,N;
int main() {
    cin>>M>>N;
    int minValue = 0;
    int sumValue = 0;
    for(int i = M; i <= N; i++) {
        if(isPrime(i)) {
            if(!minValue) minValue = i;
            sumValue += i;
        }
    }
    if(minValue) {
        cout<<sumValue<<endl;
        cout<<minValue<<endl;
    } else {
        cout<<-1<<endl;
    }
    return 0;
}
