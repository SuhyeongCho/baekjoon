#include<iostream>

using namespace std;


int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int N; cin>>N;
        long long int dp[101] = {0,1,1,1,2,2,};
        
        for(int i=6;i<=N;i++){
            dp[i] = dp[i-5] + dp[i-1];
        }
        
        cout<<dp[N]<<endl;
    }
    return 0;
}
