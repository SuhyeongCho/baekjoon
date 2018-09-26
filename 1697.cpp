#include <iostream>
#include <queue>
using namespace std;
#define MAX 100500
bool isVisited[MAX+1];
queue<int> q;
int a,b;
int s;
void bfs(){
    isVisited[a] = true;
    q.push(a);
    while(!q.empty()){
        int sizes = q.size();
        for(int i=0;i<sizes;i++){
            int m = q.front(); q.pop();
            if(m == b)return;
            if(m>=1 && !isVisited[m-1]){
                q.push(m-1); isVisited[m-1] = true;
            }
            if(m<=MAX-1 && !isVisited[m+1]){
                q.push(m+1); isVisited[m+1] = true;
            }
            if(m*2<=MAX && !isVisited[m*2]){
                q.push(m*2); isVisited[m*2] = true;
            }
        }
        s++;
    }
}
int main(){
    cin>>a>>b;
    bfs();
    cout<<s<<'\n';
    return 0;
}

