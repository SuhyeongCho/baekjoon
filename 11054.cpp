#include<iostream>

using namespace std;
int N;
int arr[1001];
int dp[2][1001];
int main(){
    cin>>N;
    
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    
    for(int i=1;i<=N;i++){
        int Max = 0;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j] && Max < dp[0][j]){
                Max = dp[0][j];
            }
        }
        dp[0][i] = Max + 1;
    }

    for(int i=N;i>=1;i--){
        int Max = 0;
        for(int j=N;j>i;j--){
            if(arr[i] > arr[j] && Max < dp[1][j]){
                Max = dp[1][j];
            }
        }
        dp[1][i] = Max + 1;
    }
//
//    for(int i=1;i<=N;i++)
//        cout<<dp[0][i] + dp[1][i] - 1<<" ";
//    cout<<endl;
    
    
    int Max = 0;
    for(int i=1;i<=N;i++){
        if(Max < dp[0][i] + dp[1][i] - 1) Max = dp[0][i] + dp[1][i] - 1;
    }
    
    cout<<Max<<endl;
    return 0;
}
