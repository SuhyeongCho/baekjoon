#include<iostream>

using namespace std;

long long int dp[2000][2000];

int main(){
    while(1){
        int n,r; cin>>n>>r;
        if(n==0&&r==0) return 0;

        if(r==0||n==r){
            cout<<1<<endl;
        }
        else{
            dp[1][0] = 1;
            dp[1][1] = 1;
            for(int i=2;i<=n;i++){
                dp[i][0] = 1;
                dp[i][i] = 1;
                for(int j=1;j<=r;j++){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                    printf("%d ,%d : %lld\n",i,j,dp[i][j]);
                }
            }
            cout<<dp[n][r]<<endl;
        }
    }
    return 0;
}
