#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int arr[1001] = {0,};
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }
    int result = 0;
    for (int i = 0 ; i <= 10000 ; i++) {
        int count1 = 0;
        int count2 = 0;
        for (int j = 0 ; j < N ; j++) {
            if (arr[j] >= i) count1++;
            if (arr[j] <= i) count2++;
        }

        if (count1 >= i && count2 >= N - i) {
            result = i;
            break;
        }
    }

    cout << result << endl;
    return 0;
}