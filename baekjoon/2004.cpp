#include <iostream>
#include <algorithm>

#define MAX 2000000000
using namespace std;

int count2(int num) {
    int result = 0;
    long long int mul = 2;
    while (mul <= MAX) {
        result += num / mul;
        mul *= 2;
    }
    return result;
}

int count5(int num) {
    int result = 0;
    long long int mul = 5;
    while (mul <= MAX) {
        result += num / mul;
        mul *= 5;
        cout << mul <<endl;

    }
    return result;
}

int main() {
    
    int N, K; cin >> N >> K;
    
    int value2 = count2(N) - count2(K) - count2(N - K);
    int value5 = count5(N) - count5(K) - count5(N - K);

    int result = min(value2, value5);
    cout << result << endl;
    
    return 0;
    
}
