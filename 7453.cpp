#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v[4];

vector<int> fc(int a,int b){
    vector<int> ret;
    for(int i=0;i<v[a].size();i++){
        for(int j=0;j<v[b].size();j++){
            ret.push_back(v[a][i] + v[b][j]);
        }
    }
    
    return ret;
}


int main(){
    
    int N; cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            int tmp; scanf("%d",&tmp);
            v[j].push_back(tmp);
        }
    }
    long long int cnt = 0;
    
    vector<int> AB = fc(0,1);
    vector<int> CD = fc(2,3);
    sort(CD.begin(),CD.end());
    
    vector<int>::iterator lo,up;
    for(int i=0;i<AB.size();i++){
        int d = AB[i];
        
        
        lo = lower_bound(CD.begin(),CD.end(),-d);
        up = upper_bound(CD.begin(),CD.end(),-d);

        cnt += (up - lo);
    }
    
    cout<<cnt<<endl;
    
}
