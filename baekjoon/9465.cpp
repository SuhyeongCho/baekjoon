#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        int *arr[2];
        int *dp[2];
        cin>>n;
        for(int i=0;i<2;i++){
            arr[i] = new int[n];
            dp[i] = new int[n];
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        
        for(int i=2;i<n;i++){
            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + arr[1][i];
        }
        
        cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
    }
    return 0;
}
