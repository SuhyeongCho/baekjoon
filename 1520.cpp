#include<iostream>

using namespace std;

int M,N;
int map[501][501];
int dp[501][501];

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int fc(int y,int x){
    if(y == M && x == N) return 1;
    dp[y][x] = 0;
    for(int i=0;i<4;i++){
        int y1 = y + dir[i][0];
        int x1 = x + dir[i][1];
        
        
        if(y1 > 0 && x1 > 0 && y1 <= M && x1 <= N){
            if(map[y1][x1] < map[y][x]){
                if(dp[y1][x1] == -1)
                    dp[y1][x1] = fc(y1,x1);
                dp[y][x] += dp[y1][x1];
            }
        }
    }
    return dp[y][x];
}

int main(){
    cin>>M>>N;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&map[i][j]);
    
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            dp[i][j] = -1;
    
    
    cout<<fc(1,1)<<endl;
    
    return 0;
}
