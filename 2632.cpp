#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v[2];
int getNext(int i,int j,int m){
    if(j +i >= m){
        return j + i -m;
    }
    else{
        return j + i;
    }

}
int main(){
    
    int N; cin>>N;
    int m,n; cin>>m>>n;
    
    for(int i=0;i<m;i++){
        int d;
        scanf("%d",&d);
        v[0].push_back(d);
    }
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        v[1].push_back(d);
    }
    
    for(int i=1;i<m;i++){
        for(int j=0;j<m;j++){
            v[0].push_back(v[0][(i-1)*m + j]+v[0][getNext(i,j,m)]);
            if(i == m-1) break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            v[1].push_back(v[1][(i-1)*n + j]+v[1][getNext(i,j,n)]);
            if(i == n-1) break;

        }
    }
    
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    
    long long int cnt = 0;;
    vector<int>::iterator up,lo;
    
    up = upper_bound(v[0].begin(),v[0].end(),N);
    lo = lower_bound(v[0].begin(),v[0].end(),N);

    cnt += (up - lo);
    
    up = upper_bound(v[1].begin(),v[1].end(),N);
    lo = lower_bound(v[1].begin(),v[1].end(),N);
    
    cnt += (up - lo);
    
    for(int i=0;i<v[0].size();i++){
        int d = v[0][i];
        
        up = upper_bound(v[1].begin(),v[1].end(),N-d);
        lo = lower_bound(v[1].begin(),v[1].end(),N-d);
        
        cnt += (up - lo);
    }
    
    cout<<cnt<<endl;
    return 0;
}
