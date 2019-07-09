#include<iostream>

int n;
long long int dp[10] = {0,1,1,1,1,1,1,1,1,1};
using namespace std;

int main(){
    
    cin>>n;
    
    long long int tmp[10] = {0};
    
    for(int i=1;i<n;i++){
        copy(dp,dp+10,tmp);
        for(int j=0;j<10;j++){
            if(j == 0) dp[j] = tmp[1];
            else if(j == 9) dp[j] = tmp[8];
            else dp[j] = (tmp[j-1] + tmp[j+1]) % 1000000000;
        }
    }
    long long int sum = 0;
    for(int i=0;i<10;i++){
        sum = (sum + dp[i]) % 1000000000;
    }
    cout<<sum<<endl;
    return 0;
}
