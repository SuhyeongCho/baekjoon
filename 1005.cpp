#include<iostream>
#include<algorithm>
using namespace std;
 
int N,K;
int arr[1001];
int dp[1001];
bool map[1001][1001];

int fc(int ret){
    // cout<<"i : "<<ret<<endl;
    if(dp[ret] == -1){
        // cout<<"NONO"<<endl;
        int maxValue = -1;
        for(int i=1;i<=N;i++){
            if(map[ret][i]){
                maxValue = max(maxValue,fc(i));
            }
        }
        if(maxValue == -1) dp[ret] = arr[ret];
        else dp[ret] = maxValue + arr[ret];
    }
    return dp[ret];
}

int main(){
    int T;cin>>T;
    
    for(int t=0;t<T;t++){
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            dp[i] = -1;
            for(int j=1;j<=N;j++){
                map[i][j] = 0;
            }
        }
        for(int i=1;i<=N;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=K;i++){
            int x,y;
            cin>>x>>y;
            map[y][x] = 1;
        }
        int result;
        cin>>result;
        // for(int i=1;i<=N;i++){
        //     cout<<fc(i)<<endl;
        // }
        cout<<fc(result)<<endl;
    }
    return 0;
}