#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int arr[100001];
int dp[100001];

int main(){
    
    int N; cin >> N;
    
    for (int i = 1 ; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1 ; i <= N ; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
    
    int maxValue = INT_MIN;
    
    for (int i = 1 ; i <= N ; i++) {
        if (maxValue < dp[i]) maxValue = dp[i];
    }
    
    cout << maxValue <<endl;
    return 0;
}

