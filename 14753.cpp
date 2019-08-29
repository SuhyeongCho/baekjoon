#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int N; cin >> N;
    vector<int> arr(N);

    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());

    int case1 = arr[0] * arr[1];
    int case2 = arr[0] * arr[1] * arr[2];
    int case3 = arr[N - 1] * arr[N - 2];
    int case4 = arr[N - 1] * arr[N - 2] * arr[N - 3];
    int case5 = arr[0] * arr[1] * arr[N - 1];
    int case6 = arr[0] * arr[N - 1] * arr[N - 2];
    int case7 = arr[0] * arr[N - 1];

    int result = max( {case1, case2, case3, case4, case5, case6, case7} );

    cout << result << endl;
    return 0;
}