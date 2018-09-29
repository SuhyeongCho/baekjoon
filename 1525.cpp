#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

bool isVisited[3][3];//[a]->[b]로 이동했다
int x0;int y0;
int map[3][3];

void bfs(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<9;i++) cin>>map[i/3][i%3];
    
    return 0;
}



