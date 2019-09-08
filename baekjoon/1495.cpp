#include <iostream>

using namespace std;

int N,S,M;
int arr[101];
bool dp[101][1001];

int main(){
    cin>>N>>S>>M;
    dp[0][S] = 1;

    for(int i=1;i<=N;i++) cin>>arr[i];

    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(!dp[i-1][j]) continue;

            int k1 = j + arr[i];
            int k2 = j - arr[i];

            if(k1 <= M) dp[i][k1] = 1;
            if(k2 >= 0) dp[i][k2] = 1;
        }
    }

 
    for(int i=M;i>=0;i--){
        if(dp[N][i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}