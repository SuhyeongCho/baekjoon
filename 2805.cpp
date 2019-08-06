#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {

    int N, M; cin >> N >> M;
    int arr[1000000] = {0,};
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    long long int left = 0;
    long long int right = LLONG_MAX;
    long long int max = 0;

    while (left <= right) {
        long long int mid = (left + right) / 2 ;
        long long int result = 0;
        for (int i = 0 ; i < N ; i++) {
            if (arr[i] > mid) result += (arr[i] - mid);
        }
        if (result < M) {
            right = mid - 1;
        } else if (result >= M) {
            left = mid + 1;
            if (max < mid) max = mid;
        }
    }

    cout << max << endl;
    return 0;
}