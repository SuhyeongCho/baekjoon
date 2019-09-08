#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
int arr[1001][1001];
int dp[1001][1001];

int main(){
    
    cin>>N>>M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i][j] = arr[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout<<dp[N][M]<<endl;
    return 0;
}
