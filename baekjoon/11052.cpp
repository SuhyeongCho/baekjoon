#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int dp[1001]={0,};
vector<int> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        v.push_back(d);
    }
    
    for(int i=1;i<=n;i++){
        int m = v[i-1];
//        cout<<" m : "<<m<<endl;
        for(int j=0;j<=i/2;j++){
            m = max(m,dp[j] + dp[i-j]);
        }
        dp[i] = m;
//        cout<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
    
    return 0;
}
