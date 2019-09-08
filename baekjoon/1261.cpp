#include<iostream>
#include<vector>
#include<queue>
#define INF 2147483647

using namespace std;
 

int **map;
int N,M;



int main(){
    
    //행이 M, 열이 N
    cin>>N>>M;
    string tmp;
    
    map = new int*[M];
    for(int i=0;i<M;i++){
        map[i] = new int[N];
    }
    
    for(int i=0;i<M;i++){
        cin>>tmp;
        for(int j=0;j<N;j++){
            map[i][j] = tmp[j] - '0';
        }
    }
  
    
    
    vector<pair<int,int> > *adj = new vector<pair<int,int> >[N*M];
    vector<int> dist(N*M,INF);
    dist[0] = 0;
    
      for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(i-1 >= 0) adj[i*N+j].push_back(make_pair((i-1)*N+j,map[i-1][j]));
            if(i+1 < M) adj[i*N+j].push_back(make_pair((i+1)*N+j,map[i+1][j]));
            if(j-1 >= 0) adj[i*N+j].push_back(make_pair(i*N+(j-1),map[i][j-1]));
            if(j+1 < N) adj[i*N+j].push_back(make_pair(i*N+(j+1),map[i][j+1]));
        }
    }
    
    
    
    priority_queue<pair<int,int> > pq;
    
    pq.push(make_pair(0,0));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
		// cout<<" cost : "<<cost<<" here : "<<here<<endl;
		
        if(dist[here] < cost) continue;
        
        for(int i=0;i<adj[here].size();i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    if(dist[N*M-1] == INF) cout<<0<<endl;
    else cout<<dist[N*M-1]<<endl;
    
    return 0;
}
