#include<iostream>

using namespace std;

unsigned long long int dp[101][101];
unsigned long long int com(int n,int r){
    if(n==r||r==0){
        return 1;
    }
    if(dp[n][r]!=-1) return dp[n][r];
    else return dp[n][r] = com(n-1,r-1)+com(n-1,r);
}
int main(){
    int n,r; cin>>n>>r;
    for(int i=0;i<101;i++)for(int j=0;j<101;j++)dp[i][j] = -1;
    cout<<com(n,r);
}
