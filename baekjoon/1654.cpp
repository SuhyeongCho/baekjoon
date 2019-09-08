#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {

    int K, N; cin >> K >> N;
    int arr[10001] = {0,};
    for (int i = 0 ; i < K ; i++) {
        scanf("%d", &arr[i]);
    }

    long long int left = 0;
    long long int right = LLONG_MAX;
    long long int max = 0;
    while (left <= right) {
        long long int mid = (left + right) / 2 ;
        int count = 0;
        for (int i = 0 ; i < K ; i++) {
            count += (arr[i] / mid);
        }
        if (count < N) {
            right = mid - 1;
        } else if (count >= N) {
            left = mid + 1;
            if (max < mid) max = mid;
        }
    }

    cout << max << endl;
    return 0;
}