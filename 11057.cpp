#include<iostream>

using namespace std;

int n;
long long int dp[10] = {1,1,1,1,1,1,1,1,1,1};
long long int tmp[10];
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        copy(dp,dp+10,tmp);
        for(int j=0;j<10;j++) dp[j] = 0;
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                dp[k] = (dp[k] + tmp[j]) % 10007;
            }
        }
    }
    
    long long int sum = 0;
    for(int i=0;i<10;i++){
        sum = (sum + dp[i]) % 10007;
    }
    
    cout<<sum<<endl;
    return 0;
}
