#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> v(N);
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    long long int left = 1;
    long long int right = v[N - 1] - v[0];

    long long int result = 0;

    while (left <= right) {

        long long int mid = (left + right) / 2;
        long long cnt = 1;
        int start = v[0];

        for (int i = 1 ; i < N ; i++) {
            if (v[i] - start >= mid){
                cnt++;
                start = v[i];
            }
        }

        if (cnt < C) right = mid - 1;
        else {
            left = mid + 1;
            if (result <= mid) result = mid;
        }
    }

    cout << result << endl;
    return 0;
}