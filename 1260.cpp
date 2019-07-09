#include<iostream>
#include<cstring>
using namespace std;

bool visit[1001];
bool map[1001][1001];
int arr[100001];
int front = 0;
int back = 1;

void push(int x){ arr[back++] = x; }
int pop(){ return  front+1!=back?arr[++front]:-1; }
int Size(){ return back-front-1; }
bool isEmpty(){ return Size()?0:1; }
int Front(){return Size()?arr[front+1]:-1;}
int Back(){return Size()?arr[back-1]:-1;}

int n,m;
void DFS(int here){
    visit[here] = true;
    cout<<here<<" ";
    for(int i=1;i<=n;i++){
        int there = map[here][i];
        if(there && !visit[i]) DFS(i);
    }
}

void BFS(int here){
    visit[here] = true;
    push(here);
    while(!isEmpty()){
        int q = pop();
        cout<<q<<" ";
        for(int i=1;i<=n;i++){
            int there = map[q][i];
            if(there && !visit[i]){
                push(i);
                visit[i] = true;
            }
        }
    }
}
int main(){
    int v;
    cin>>n>>m>>v;
    for(int i=0;i<n+1;i++)for(int j=0;j<n+1;j++)map[i][j]=false;
    for(int i=0;i<n+1;i++)visit[i]=false;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        map[a][b] = true;
        map[b][a] = true;
    }
    DFS(v);
    cout<<endl;
    for(int i=0;i<n+1;i++)visit[i]=false;
    BFS(v);
    cout<<endl;
    
}

