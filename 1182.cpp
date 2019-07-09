#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int N,S;

int *arr;
set< vector<int> > s;
//i는 위치, sum은 합, t는 몇개를 더했는지
void fc(int i,int sum,vector<int> v){
//    cout<<" i : "<<i<<" sum : "<<sum<<endl;
    
    
    if(i>N){
        return;
    }
    if(sum == S && !v.empty()){
        sort(v.begin(),v.end());
        s.insert(v);
    }
    v.push_back(i);
    fc(i+1,sum+arr[i],v);
    v.pop_back();
    fc(i+1,sum,v);
    
    return;
}



int main(){
    
    cin>>N>>S;
    
    arr = new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    vector<int> v;
    fc(0,0,v);
    
    cout<<s.size()<<endl;
    return 0;
}

