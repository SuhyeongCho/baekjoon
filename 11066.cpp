#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits.h>
#define INF INT_MAX

using namespace std;

int main(){
    int T;cin>>T;
    for(int t=0;t<T;t++){
        int N; cin>>N;
        int arr[501];
        int dp[501][501];
        int sum[501];
        
        memset(dp,0,501*501*sizeof(int));
        memset(sum,0,501*sizeof(int));
        
        for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
        
        for(int i=1;i<=N;i++) sum[i] = sum[i-1] + arr[i];
        
        for(int i=1;i<=N;i++) dp[i][i] = arr[i];
        
        for(int i=1;i<N;i++){
            for(int x=1;x+i<=N;x++){
                int y = x+i;
                dp[x][y] = INF;
                for(int j=x;j<y;j++){
                    dp[x][y] = min(dp[x][y],dp[x][j]+dp[j+1][y]);
                }
                dp[x][y] += (sum[y] - sum[x-1]);
            }
            
        }
        
        cout<<dp[1][N] - sum[N]<<endl;
        

    }
    

    
    return 0;
}
