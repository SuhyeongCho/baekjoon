#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int arr[100001];
int dp[100001];

int main(){
    
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
    }
    
    int Max = INT_MIN;
    for(int i=1;i<=n;i++){
        if(Max < dp[i]) Max = dp[i];
    }
    
    cout<<Max<<endl;
    return 0;
}

