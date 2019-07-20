#include<iostream>

using namespace std;

int M,N;
int map[501][501];
int dp[501][501];

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int fc(int x, int y) {

    if (x == M && y == N) return 1;
    else if (x < 1 && y < 1) return 0;
    
    if (dp[x][y] != -1) return dp[x][y];
    
    int sum = 0;
    
    if (map[x][y] > map[x + 1][y]) sum += fc(x + 1, y);
    if (map[x][y] > map[x][y + 1]) sum += fc(x, y + 1);
    if (map[x][y] > map[x - 1][y]) sum += fc(x - 1, y);
    if (map[x][y] > map[x][y - 1]) sum += fc(x, y - 1);

    dp[x][y] = sum;
    
    return dp[x][y];
    
}

int main(){
    
    cin>>M>>N;
    for(int i = 1 ; i <= M ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i = 1 ; i <= M ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout<<fc(1,1)<<endl;
    
    return 0;
}
