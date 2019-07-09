#include<iostream>

using namespace std;

int N;
long long int dp[31];

int main(){
    cin>>N;
    
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i=4;i<=N;i+=2){
        dp[i] = 3 * dp[i-2];
        for(int j=4;j<=i;j+=2){
            dp[i] += 2*dp[i-j];
        }
    }
    
    cout<<dp[N]<<endl;
    return 0;
}
