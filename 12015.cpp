#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int N; cin >> N;
    int arr[1000000] = {0,};
    vector<int> v;

    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }
    v.push_back(INT_MIN);
    for (int i = 0 ; i < N ; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
        } else {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), arr[i]);
            *iter = arr[i];
        }
    }

    cout << v.size() - 1 << endl;

    return 0;
}