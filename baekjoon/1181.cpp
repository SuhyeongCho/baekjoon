#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
set<pair<int,string> > v;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; int d;
        cin>>s;
        d = s.length();
        v.insert(make_pair(d,s));
    }

    set<pair<int,string> >::iterator iter;
    for(iter=v.begin();iter!=v.end();iter++){
        cout<<(*iter).second<<endl;
    }
    return 0;
}