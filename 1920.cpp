#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
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
        if (upper_bound(arr, arr + N , d) - lower_bound(arr, arr + N, d) ) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}