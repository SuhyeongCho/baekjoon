#include <iostream>
using namespace std;

int lotto[13];
int combi[13];

void dfs(int start,int cnt,const int N){
    if(cnt == 6){
        for(int i=0;i<6;i++){
            cout<<combi[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start;i<N;i++){
        combi[cnt] = lotto[i];
        dfs(i+1,cnt+1,N);
    }
    
}
int main(){
    int N = 1;
    while(N){
        int start=0, cnt = 0;
        cin>>N;
        if(N==0) return 0;
        for(int i=0;i<N;i++) cin>>lotto[i];
        dfs(start,cnt,N);
        cout<<'\n';

    }
}
