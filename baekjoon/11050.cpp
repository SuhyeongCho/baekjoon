#include<iostream>

using namespace std;

int dp[11][11];
int main(){
    int N, K; cin >> N >> K;
    
    for (int i = 1 ; i <= N ; i++) {
        dp[i][0] = 1; dp[i][i] = 1;
        for (int j = 1 ; j <= i - 1 ; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    cout << dp[N][K] << endl;
    return 0;
}
