#include<iostream>

using namespace std;

int N;
long long int dp[2] = {0,1};
int main(){
    cin>>N;
    
    for(int i=0;i<N-2;i++){
        long long int tmp = dp[1];
        dp[1] = dp[0];
        dp[0] = dp[0] + tmp;
    }
    
    cout<<dp[0]*2 + dp[1]<<endl;
}
