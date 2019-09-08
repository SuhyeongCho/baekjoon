#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];
int main() {
    int N, M;
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0 ; i < M ; i++) {
        int d; scanf("%d", &d);
        printf("%d ", upper_bound(arr, arr + N , d) - lower_bound(arr, arr + N, d) );
    }
    cout << endl;
    return 0;
}