#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits.h>
#define INF INT_MAX

using namespace std;

int main(){
    int T; cin >> T;
    
    for(int t = 0 ; t < T ; t++) {
        
        int N; cin >> N;
        int arr[501] = {0,};
        int dp[501][501] = {0,};
        int sum[501] = {0,};
        
        for (int i = 1 ; i <= N; i++) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
        }

        
        for (int d = 2 ; d <= N ; d++) {
            for (int i = 1; i <= N - d + 1 ; i++) {
                int j = d + i - 1;
                dp[i][j] = INT_MAX;
                for (int k = i ; k < j ; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] += sum[j] - sum[i - 1];
            }
        }
        
        cout << dp[1][N] << endl;
        
        
        
    }
    
    return 0;
}
