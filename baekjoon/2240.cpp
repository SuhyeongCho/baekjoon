#include <iostream>
#include <algorithm>

using namespace std;

int T,W;
int arr[1001];
int dp[1001][31];
int main(){
    cin>>T>>W;

    for(int i=1;i<=T;i++){
        cin>>arr[i];
    }

    if(arr[1] == 1) dp[1][0] = 1;
    else if(arr[1] == 2) dp[1][1] = 1;

    for(int i=2;i<=T;i++){
        for(int j=0;j<=W;j++){
            if(i < j) continue;
            int plus = 0;
            if(j%2 == 0 && arr[i] == 1) plus = 1;
            else if(j%2 == 1 && arr[i] == 2) plus = 1;

            if(j == 0) dp[i][j] = dp[i-1][j] + plus;
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + plus;
        }
    }
    
    // for(int i=1;i<=T;i++){
    //     for(int j=0;j<=W;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int max = 0;
    for(int i=0;i<=W;i++){
        if(max < dp[T][i]) max = dp[T][i];
    }
    cout<<max<<endl;
    return 0;
}