#include<iostream>

using namespace std;

int main(){
    int N, K; cin >> N >> K;
    
    int arr[101] = {0,};
    int dp[10001] = {0,};
    
    for (int i = 1; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    dp[0] = 1;
    
    for (int i = 1 ; i <= N ; i++) {
        int coin = arr[i];
        for (int j = 1 ; j <= K ; j++) {
            if (coin <= j) dp[j] = dp[j] + dp[j - coin];
        }
    }
    
    cout << dp[K] << endl;
    
    return 0;
}
