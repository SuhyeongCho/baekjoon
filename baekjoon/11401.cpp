#include<iostream>
#define MOD 1000000007

using namespace std;

int N, K;
long long int fac[4000001];
void factorial(int n) {
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        fac[i] = (i * fac[i - 1]) % MOD;
    }
}
long long int solve(int n, int a) {
    if (n == 0) return 1;

    long long int tmp = solve(n / 2, a);
    long long int result = (tmp * tmp) % MOD;
    if (n % 2) return (result * a) % MOD;
    else return result;
}

int main(){
    cin >> N >> K;
    factorial(N);
    cout << (((fac[N] * solve(MOD - 2, fac[N - K])) % MOD) * solve (MOD - 2, fac[K])) % MOD << endl;

    return 0;
}
