#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v[2];

int main(){
    int T; cin>>T;
    int n,m;
    
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        
        if(i>0) v[0].push_back(v[0][i-1] + d);
        else v[0].push_back(d);
    }
    
    cin>>m;
    for(int i=0;i<m;i++){
        int d;
        scanf("%d",&d);
        
        if(i>0) v[1].push_back(v[1][i-1] + d);
        else v[1].push_back(d);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            v[0].push_back(v[0][i] - v[0][j]);
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            v[1].push_back(v[1][i] - v[1][j]);
        }
    }
    
    
    sort(v[1].begin(),v[1].end());
    long long int cnt = 0;
    vector<int>::iterator lo,up;
    for(int i=0;i<v[0].size();i++){
        int d = v[0][i];
        lo = lower_bound(v[1].begin(),v[1].end(),T-d);
        up = upper_bound(v[1].begin(),v[1].end(),T-d);

        cnt += (up - lo);
    }
    
    cout<<cnt<<endl;
    
    return 0;
}

