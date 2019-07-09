#include<iostream>
#include<algorithm>

using namespace std;


int arr[302] = {0,};
int dp[302] = {0,};

int main(){
    
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-3]+arr[i-1],dp[i-2]) + arr[i];
    }
    
    cout<<dp[n]<<endl;
    return 0;
}
