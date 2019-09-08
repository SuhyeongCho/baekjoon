#include <iostream>
#include <algorithm>

using namespace std;

long long int arr[100000];

long long int solve(int left, int right) {

    if (left == right) return arr[left];
    int mid = (left + right) / 2;

    int lo = mid;
    int hi = mid + 1;

    long long int height = min(arr[lo], arr[hi]);
    long long int result = max(2 * height, max(solve(left, mid), solve(mid + 1, right)));

    while(left < lo || hi < right) {
        if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1])) {
            hi++;
            height = min(height, arr[hi]);
        } else {
            lo--;
            height = min(height, arr[lo]);
        }
        result = max(result, height * (hi - lo + 1));
    }
    return result;
}
int main() {
    while(1) {
        int N; cin >> N;
        if (N == 0) break;
        for (int i = 0 ; i < N ; i++) {
            scanf("%d", &arr[i]);
        }
        cout << solve(0, N - 1) << endl;
    }

    return 0;
}