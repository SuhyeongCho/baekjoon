
#include<iostream>
#include<algorithm>
#include<limits.h>
#define INF INT_MAX

using namespace std;

int n,k;
unsigned int dp[10001];
int coin[101];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>coin[i];
    for(int i=1;i<=k;i++) dp[i] = INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j >= coin[i])dp[j] = min(dp[j],dp[j-coin[i]]+1);
        }
    }
    
    if(dp[k] >= INF) cout<<-1<<endl;
    else cout<<dp[k]<<endl;
    return 0;
}
