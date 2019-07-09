#include <iostream>

using namespace std;

int n;
int dp[31];
int main(){
    cin>>n;
    
    dp[1] = 1;
    dp[2] = 3;
    if(n <= 2){
        cout<<dp[n]<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
    int result = 0;
    if(n%2 == 0){
        result = (dp[n]+dp[n/2]+dp[n/2-1]*2)/2;
    }
    else{
        result = (dp[n]+dp[n/2])/2;
    }
    cout<<result<<endl;
    return 0;
}