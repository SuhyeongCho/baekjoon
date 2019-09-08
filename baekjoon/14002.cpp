#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
int arr[1001];
int trace[1001];

int main() {
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1 ; i <= N ; i++) {
        if (dp[i] == 0) dp[i] = 1;
        for (int j = 1 ; j < i ; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
    }
    int maxValue = 0;
    int current = 0;
    for (int i = 1 ; i <= N ; i++) {
        if (dp[i] > maxValue){
            maxValue = dp[i];
            current = i;
        }
    }

    cout << maxValue << endl;

    vector<int> v;
    while (current != 0) {
        v.push_back(arr[current]);
        current = trace[current];
    }

    int siz = v.size();
    for (int i = 0 ; i < siz ; i++) {
        printf("%d ",v.back());
        v.pop_back();
    }
    cout << endl;
    return 0;
}