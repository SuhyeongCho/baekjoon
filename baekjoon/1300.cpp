#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    long long int N, K;
    cin >> N >> K;

    long long int left = 1;
    long long int right = N * N;
    long long int result = 0;

    while (left <= right) {
        long long int mid = (left + right) / 2;
        long long int count = 0;

        for (int i = 1 ; i <= N ; i++) {
            count += min(mid / i, N);
        }

        if (count < K) {
            left = mid + 1;
        } else {
            result = mid;
            right = mid - 1;
        }
    }
    cout << result << endl;  
    return 0;
}