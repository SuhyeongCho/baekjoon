#include<iostream>
#include<stdio.h>

using namespace std;

int N,M;
int arr[2001];
int dp[2001][2001];

int main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    cin>>M;
    
    for(int i=1;i<=N;i++) dp[i][i] = 1;
    for(int i=1;i<=N-1;i++){
        if(arr[i] == arr[i+1])
            dp[i][i+1] = 1;
    }
    
    for(int i=3;i<=N;i++){
        for(int j=1;j<=N-i+1;j++){
            dp[j][j+i-1] = (arr[j]==arr[j+i-1] && dp[j+1][j+i-2]);
        }
    }
    
    for(int i=0;i<M;i++){
        int S1,E1;
        scanf("%d %d",&S1,&E1);
        printf("%d\n",dp[S1][E1]);
    }
    
    return 0;
}

