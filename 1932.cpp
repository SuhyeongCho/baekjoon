#include <iostream>
#include <algorithm>

using namespace std;

int arr[500][500];
int dp[500][500];
int main(){
    
    int N; cin >> N;
    for (int i = 0 ; i < N; i++) {
        for (int j = 0 ; j <= i ; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for (int i = 1 ; i < N ; i++) {
        for (int j = 0; j <= i ; j++) {
            dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int result = 0;
    for (int i = 0 ; i < N ; i++) {
        result = max(result, dp[N - 1][i]);
    }

    cout << result <<endl;
    return 0;
}
