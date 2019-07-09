#include<iostream>

using namespace std;
int N;
int arr[1001];
int dp[1001];
int main(){
    cin>>N;
    
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    
    for(int i=1;i<=N;i++){
        int Max = 0;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j] && Max < dp[j]){
                Max = dp[j];
            }
        }
        dp[i] = Max + 1;
    }
    
    int Max = 0;
    for(int i=1;i<=N;i++){
        if(Max < dp[i]) Max = dp[i];
    }
    
    cout<<Max<<endl;
    return 0;
}
