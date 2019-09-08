#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int n;
int arr[500001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    double sum = 0;
    for(int i=1;i<=n;i++){
        sum += arr[i];
    }
    cout<<round(sum/n)<<endl;
    cout<<arr[(n+1)/2]<<endl;

    vector<pair<int,int> >v;
    v.push_back(make_pair(-1,arr[1]));
    for(int i=2;i<=n;i++){
        if(v.back().second == arr[i]){
            int tmp = v.back().first;
            v.pop_back();
            v.push_back(make_pair(tmp-1,arr[i]));
        }
        else{
            v.push_back(make_pair(-1,arr[i]));
        }
        
    }
    sort(v.begin(),v.end());
        if(v[0].first == v[1].first){
            cout<<v[1].second<<endl;
        }
        else{
            cout<<v[0].second<<endl;
        }

    cout<<arr[n]-arr[1]<<endl;
    return 0;
}