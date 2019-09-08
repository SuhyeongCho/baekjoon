#include<iostream>

using namespace std;

long long int dp[101][101];

int main(){
    int n,r; cin>>n>>r;
    if(r==0||n==r) cout<<1<<endl;
    else{
        dp[1][0] = dp[1][1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        cout<<dp[n][r]<<endl;
    }
    return 0;
}
