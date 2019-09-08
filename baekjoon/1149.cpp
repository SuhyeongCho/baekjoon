#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1001][3];
int dp[3][1001];


int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        cin>>arr[i][2];
    }

    dp[0][1] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[2][1] = arr[1][2];

    for (int i = 2 ; i <= N ; i++) {
        dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = arr[i][1] + min(dp[2][i - 1], dp[0][i - 1]);
        dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
    }
    cout<<min(dp[0][N],min(dp[1][N],dp[2][N]))<<endl;
    return 0;
}
