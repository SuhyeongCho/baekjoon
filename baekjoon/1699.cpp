#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;


int N;
vector<int> square;
int dp[100001];
int main(){
    
    cin>>N;
    
    for(int i=1;i*i<=N;i++){
        square.push_back(i*i);
    }
    
    dp[1] = 1;
    
    int pos = 0;
    int sq = square[pos];
    for(int i=2;i<=N;i++){
        if(i == square[pos+1]) pos++;
        int Min = INT_MAX;
        for(int j=0;j<=pos;j++)
            if(Min > dp[i-square[j]])
                Min = dp[i - square[j]];
        dp[i] = min(Min, dp[i-1]) + 1;
    }


    cout<<dp[N]<<endl;
    return 0;
}
