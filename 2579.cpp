#include<iostream>
#include<algorithm>

using namespace std;

int arr[301];
int dp[301];

int main(){
    
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for (int i = 3 ; i <= N ; i++) {
        dp[i] = max(dp[i - 2], arr[i - 1] + dp[i - 3]) + arr[i];
    }
    
    cout << dp[N] <<endl;
    
    return 0;
}
