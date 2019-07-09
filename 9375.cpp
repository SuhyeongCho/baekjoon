#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int n; cin>>n;
        vector<pair<string,int> > v;
        for(int i=0;i<n;i++){
            string s1,s2;
            cin>>s1>>s2;
            bool check = 0;
            for(int i=0;i<v.size();i++){
                if(v[i].first == s2){
                    v[i].second++;
                    check = 1;
                    break;
                }
            }
            if(check == 0){
                v.push_back(make_pair(s2,1));
            }
        }
        int result = 1;
        for(int i=0;i<v.size();i++){
            result *= v[i].second+1;
        }
        cout<<result-1<<endl;
    }
    return 0;
}