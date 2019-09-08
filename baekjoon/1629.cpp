#include <iostream>

using namespace std;

int A, B, C;

long long int solve(int N) {
    if (N == 0) return 1;
    long long int tmp = solve(N / 2);
    long long int result = (tmp * tmp) % C;
    if (N % 2) return (A * result) % C;
    else return result;
}

int main() {
    cin >> A >> B >> C;
    
    cout << solve(B) << endl;

    return 0;
}