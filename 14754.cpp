#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001][1001];

int main() {
    int N, M; cin >> N >> M;

    for(int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    vector<int> vi(N), vj(M);
    for(int i = 0 ; i < N ; i++) {
        int maxValue = 0;
        for (int j = 0 ; j < M ; j++) {
            maxValue = max(maxValue, arr[i][j]);
        }
        vi[i] = maxValue;
    }
    for(int j = 0 ; j < M ; j++) {
        int maxValue = 0;
        for (int i = 0 ; i < N ; i++) {
            maxValue = max(maxValue, arr[i][j]);
        }
        vj[j] = maxValue;
    }
    
    long long int result = 0;
    for(int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (arr[i][j] != vi[i] && arr[i][j] != vj[j]) {
                result += arr[i][j];
            }
        }
    }

    cout << result << endl;
    return 0;

}