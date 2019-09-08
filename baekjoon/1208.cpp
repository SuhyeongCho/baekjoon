#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,S;
vector<int> v;
vector<int> vsum[2];

void fc(int AB,int i,int sum,int end,int count){
    
    if(i>=end) return;
    vsum[AB].push_back(sum+v[i]);
    fc(AB,i+1,sum+v[i],end,count+1);
    
    fc(AB,i+1,sum,end,count+1);

}
int main(){
    cin>>N>>S;
    
    for(int i=0;i<N;i++){
        int d; scanf("%d",&d);
        v.push_back(d);
    }
    fc(0,0,0,N/2,0);
    fc(1,N/2,0,N,0);

    sort(vsum[0].begin(),vsum[0].end());
    sort(vsum[1].begin(),vsum[1].end());

    
    long long int cnt = 0;
    vector<int>::iterator lo,up;
    
    lo = lower_bound(vsum[0].begin(),vsum[0].end(),S);
    up = upper_bound(vsum[0].begin(),vsum[0].end(),S);

    cnt += (up - lo);
    
    lo = lower_bound(vsum[1].begin(),vsum[1].end(),S);
    up = upper_bound(vsum[1].begin(),vsum[1].end(),S);
    
    cnt += (up - lo);
    
    for(long long int i=0;i<vsum[0].size();i++){
        int d = vsum[0][i];
        
        lo = lower_bound(vsum[1].begin(),vsum[1].end(),S-d);
        up = upper_bound(vsum[1].begin(),vsum[1].end(),S-d);
        
        cnt += (up - lo);
    }
    
    cout<<cnt<<endl;
    
    return 0;
}
