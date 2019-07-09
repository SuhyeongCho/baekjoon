#include<iostream>

using namespace std;

int main(){
    int result = 1;
    
    int a,b,c; cin>>a>>b>>c;
    
    for(int i=0;i<15*28*19;i++,result++){
        int E,S,M;
        E = result%15;
        S = result%28;
        M = result%19;
        
        E = E?E:15;
        S = S?S:28;
        M = M?M:19;
        
        if(a==E&&b==S&&c==M){
            cout<<result<<'\n';
            return 0;
        }
    }
    return 0;
}
