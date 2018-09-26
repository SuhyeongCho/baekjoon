#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q1;
queue<string> q2;
bool isVisited[10000];

int a,b;
int makeDigit(int d1,int d2,int d3,int d4){
    return d1*1000 + d2*100 + d3*10 + d4;
}
int d1,d2,d3,d4;
//D : 2*n % 10000
//S : n-1 % 10000
//L : [d1,d2,d3,d4] -> [d2,d3,d4,d1]
//R : [d1,d2,d3,d4] -> [d4,d1,d2,d3]


void bfs(){
    q1.push(a);
    q2.push("");
    isVisited[a] = true;
    while(!q1.empty()){
        int m = q1.front(); q1.pop();
        string s = q2.front(); q2.pop();
        if(m == b){
            cout<<s<<'\n';
            return;
        }
        int D = (2*m) % 10000;
        int S = m?m-1:9999;
        
        d1 = m /1000; m%=1000;
        d2 = m /100; m%=100;
        d3 = m/10; m%=10;
        d4 = m;
        
        
        int L = makeDigit(d2,d3,d4,d1);
        int R = makeDigit(d4,d1,d2,d3);
        
        if(!isVisited[D]){
            isVisited[D] = true;
            q1.push(D);
            q2.push(s+"D");
        }
        if(!isVisited[S]){
            isVisited[S] = true;
            q1.push(S);
            q2.push(s+"S");
        }
        
        if(!isVisited[L]){
            isVisited[L] = true;
            q1.push(L);
            q2.push(s+"L");
        }
        if(!isVisited[R]){
            isVisited[R] = true;
            q1.push(R);
            q2.push(s+"R");
        }
    }
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        for(int i=0;i<10000;i++) isVisited[i] = false;
        cin>>a>>b;
        bfs();
    }
    return 0;
}


