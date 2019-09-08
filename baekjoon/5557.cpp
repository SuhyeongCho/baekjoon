#include <iostream>

using namespace std;

int N;
int arr[101];
long long int dp[101][1001];

int main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    dp[1][arr[1]] = 1;
    for(int i=2;i<=N-1;i++){
        for(int j=0;j<=20;j++){
            if(!dp[i-1][j]) continue;
            int k1 = j + arr[i];
            int k2 = j - arr[i];
            if(k1 <= 20) dp[i][k1] += dp[i-1][j];
            if(k2 >= 0) dp[i][k2] += dp[i-1][j];
        }
    }
    cout<<dp[N-1][arr[N]]<<endl;
    return 0;
}