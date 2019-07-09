#include<iostream>
#include<queue>
#include<list>
using namespace std;

int main(){
    int N,M; cin>>N>>M;
    int map[N+1][N+1];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            map[i][j] = 0;
        }
    }
    for(int i=0;i<M;i++){
        int a,b,t; cin>>a>>b>>t;
        map[a][b] = t;
        map[b][a] = t;
    }
    int u,v,w; cin>>u>>v>>w;
    unsigned int wait = 0;
    unsigned int time = 0;
    list<int> arrayU;
    while(1){
        int pos = u;
        for(int i=1;i<N+1;i++){
            if(time + map[u][i] < wait){
                arrayU.push(i);
            }
        }
            
        wait++;
    }
}
