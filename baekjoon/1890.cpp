#include<iostream>

using namespace std;

int N;
int arr[101][101];
long long int dp[101][101];

int main(){
    cin>>N;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    

    dp[N][N] = 1;
    for(int i=N;i>0;i--){
        
        int d = arr[i][i];
        if(i+d <= N && i!=N) dp[i][i] = dp[i+d][i] + dp[i][i+d];
        for(int j=i-1;j>0;j--){
            d = arr[i][j];
            if(i+d <= N) dp[i][j] += dp[i+d][j];
            if(j+d <= N) dp[i][j] += dp[i][j+d];
            
            d = arr[j][i];
            if(i+d <= N) dp[j][i] += dp[j][i+d];
            if(j+d <= N) dp[j][i] += dp[j+d][i];
            
        }
    }
    

    
    
    cout<<dp[1][1]<<endl;
    return 0;
}
