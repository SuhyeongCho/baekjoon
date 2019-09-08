#include<iostream>

using namespace std;

int *map;
int *cal;
int N,M;


int main(){
    
    cin>>N>>M;
    
    map = new int[N];
    cal = new int[N];

    
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    
    int cnt = 0;

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            cal[i] = cal[i] + map[j];
            if(cal[i] == M){
                cnt++;
                break;
            }
            else if(cal[i] > M) break;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}
