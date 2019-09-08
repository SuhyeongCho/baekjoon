#include<iostream>
#include<limits.h>
#define INF INT_MAX

using namespace std;

int N;
int arr[501];
int dp[501][501];

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i-1]>>arr[i];
    }

    
    for(int dx=2;dx<=N;dx++){
        for(int i=1;i<=N+1-dx;i++){
            int j = i+dx-1;
            dp[i][j] = INF;
            for(int k=i;k<=j-1;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
//            cout<<" dx : "<<dx<<" i : "<<i<<" j : "<<j<<" dp : "<<dp[i][j]<<endl;
        }
    }
    
    cout<<dp[1][N]<<endl;
    return 0;
}
