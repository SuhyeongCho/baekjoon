#include<iostream>
#include<cstring>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M; cin>>M;
    char command[7];
    int x;
    int S = 0;
    for(int i=0;i<M;i++){
        cin>>command;
        if(!strcmp("add",command)){
            cin>>x;
            S|=(1<<(x-1));
        }else if(!strcmp("remove",command)){
            cin>>x;
            S&=(~(1<<(x-1)));
        }else if(!strcmp("check",command)){
            cin>>x;
            int check = S&(1<<(x-1));
            if(check) cout<<1<<'\n';
            else cout<<0<<'\n';
        }else if(!strcmp("toggle",command)){
            cin>>x;
            S^=(1<<(x-1));
        }else if(!strcmp("all",command)){
            S = (1<<20)-1;
        }else if(!strcmp("empty",command)){
            S = 0;
        }
    }
}
