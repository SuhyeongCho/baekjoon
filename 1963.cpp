#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

bool isVisited[10000];
int a,b;
int depth;

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void bfs(){
    q.push(a);
    isVisited[a] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int m = q.front();q.pop();
            if(m == b)return;
            int a = m/1000; m%=1000;
            int b = m/100; m%=100;
            int c = m/10; m%=10;
            int d = m;
            for(int j = 1;j<10;j++){
                int X = j*1000+b*100+c*10+d;
                if(!isVisited[X]&&isPrime(X)){
                    isVisited[X] = true;
                    q.push(X);
                }
            }
            for(int j = 0;j<10;j++){
                int X = a*1000+j*100+c*10+d;
                if(!isVisited[X]&&isPrime(X)){
                    isVisited[X] = true;
                    q.push(X);
                }
            }
            for(int j = 0;j<10;j++){
                int X = a*1000+b*100+j*10+d;
                if(!isVisited[X]&&isPrime(X)){
                    isVisited[X] = true;
                    q.push(X);
                }
            }
            for(int j = 1;j<10;j++){
                int X = a*1000+b*100+c*10+j;
                if(!isVisited[X]&&isPrime(X)){
                    isVisited[X] = true;
                    q.push(X);
                }
            }
        }
        depth++;
        if(depth >= 100){depth = -1; return;}
    }
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        for(int i=0;i<q.size();i++) q.pop();
        for(int i=0;i<10000;i++) isVisited[i] = false;
        depth = 0;
        cin>>a>>b;
        bfs();
        if(depth == -1 )cout<<"Impossible"<<'\n';
        else cout<<depth<<endl;
    }
    return 0;
}

