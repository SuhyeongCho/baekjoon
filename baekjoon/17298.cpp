#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr(N), result(N);
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    vector<int> v;
    v.push_back(INT_MAX);
    
    for (int i = N - 1 ; i >= 0 ; i--) {
        while (v.back() <= arr[i]) v.pop_back();
        if (v.back() == INT_MAX) result[i] = -1;
        else result[i] = v.back();
        v.push_back(arr[i]);
    }
    
    for (int i = 0 ; i < N ; i++) {
        printf("%d ",result[i]);
    }
    cout << endl;
    return 0;
}
