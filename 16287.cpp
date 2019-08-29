#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int W, N;

    cin >> W >> N;

    vector<int> arr(N, 0), sum(W, 0);

    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0 ; i < N && arr[i] < W ; i++) {
        for (int j = i + 1 ; j < N && arr[j] < W ; j++) {
            int s = arr[i] + arr[j];
            if (s >= W) continue;
            if (sum[s] == 0) sum[s] = i;
        }
    }

    bool result = false;
    for (int i = 0 ; i < W ; i++) {
        int j = sum[i], k = sum[W - i];
        if (j == 0 || k == 0) continue;
        if (i - arr[j] < arr[k]){
            result = true;
            break;
        }
    }

    if (result) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}