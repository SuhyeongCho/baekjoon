#include<iostream>

using namespace std;

int *map;
int N,S;


int main(){
    
    cin>>N>>S;
    
    map = new int[N];
    
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    int min1 = N+1;
    int sum = map[0];
    int siz = 1;
    int pos = 0;
   
    for(int i = 0;;){
        if(i < N){
            if(sum < S){
                sum += map[++i];
                siz++;
            }
            else{
                if(min1 > siz) min1 = siz;
                sum -= map[pos++];
                siz--;
            }
        }
        else break;
    }
    
    
    if(min1 >= N+1) cout<<0<<endl;
    else cout<<min1<<endl;
    
    
    return 0;
}
