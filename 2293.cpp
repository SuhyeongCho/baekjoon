
#include<iostream>

using namespace std;

int n,k;
int dp[10001];
int coin[101];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>coin[i];
    
    dp[0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(coin[i] <= j) dp[j] += dp[j-coin[i]];
        }
    }
    
    cout<<dp[k]<<endl;
    return 0;
}