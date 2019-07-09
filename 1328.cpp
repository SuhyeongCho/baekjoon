#include <iostream>

using namespace std;

int N,L,R;
long long int dp[101][101][101];
int main(){

    cin>>N>>L>>R;

    dp[1][1][1] = 1;

    for(int i=2;i<=N;i++){
        for(int j=1;j<=L;j++){
            for(int k=1;k<=R;k++){
                if(i < j || i < k) continue;
                dp[i][j][k] = (dp[i-1][j][k] * (i-2) + (dp[i-1][j-1][k] + dp[i-1][j][k-1]) % 1000000007)%1000000007;
            }
        }
    }

    cout<<dp[N][L][R]<<endl;
    return 0;
}