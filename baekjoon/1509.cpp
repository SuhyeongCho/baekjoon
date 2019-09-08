
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[2501][2501];
int dp1[2501];

int main(){
    string arr;
    cin>>arr;
    int len = arr.size();
    
    for(int i=len-1;i>=0;i--){
        arr[i+1] = arr[i];
    }
    
    for(int i=1;i<=len;i++) dp[i][i] = 1;
    for(int i=1;i<=len-1;i++){
        if(arr[i] == arr[i+1])
            dp[i][i+1] = 1;
    }
    
    for(int i=3;i<=len;i++){
        for(int j=1;j<=len-i+1;j++){
            dp[j][j+i-1] = (arr[j]==arr[j+i-1] && dp[j+1][j+i-2]);
        }
    }
    
    for(int i=1;i<=len;i++){
        dp1[i]= i;
        for(int j=1;j<=i;j++){
            if(dp[j][i]){
                dp1[i] = min(dp1[i],dp1[j-1]+1);
            }
        }
    }
    
    cout<<dp1[len]<<endl;
    return 0;
}
