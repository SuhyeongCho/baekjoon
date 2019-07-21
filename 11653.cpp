#include <iostream>

using namespace std;

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    
    int N; cin >> N;
    
    int prime = 2;
    while (N > 1) {
        if (N % prime == 0 && isPrime(prime)) {
            printf("%d\n", prime);
            N /= prime;
        } else {
            prime++;
        }
    }
    return 0;
}
