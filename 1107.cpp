#include<iostream>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,M; cin>>N>>M;
    set<int> s;
    for(int i=0;i<10;i++){
        s.insert(i);
    }
    for(int i=0;i<M;i++){
        int tmp; cin>>tmp;
        s.erase(tmp);
    }
    int result = abs(N-100);
    if(M == 10){
        cout<<result<<endl;
        return 0;
    }
    set<int>::iterator iter;

    iter = s.begin();
    if(*iter == 0){
        result = min(N+1,abs(100-N));
    }
    if(N==0){
        iter = s.begin();
        result = (*iter) + 1;
        cout<<result<<endl;
        return 0;
    }
    queue<int> q;
    for(iter=s.begin();iter!=s.end();++iter){
        if(*iter == 0){
            continue;
        }
        q.push(*iter);
    }
    int count = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int value = q.front();q.pop();
            if(value > 1000000){
                cout<<result<<endl;
                return 0;
            }
            if(result > abs(N-value)+count){
                result = abs(N-value)+count;
            }
            for(iter=s.begin();iter!=s.end();++iter){
                int m = (*iter);
                q.push(value*10 +m);
//                cout<<"value : "<<value<<endl;
//                cout<<"count : "<<count<<endl;
//                cout<<"result : "<<value*10+m<<endl;
            }
        }
        count++;
    }
    cout<<result<<endl;
    return 0;
}




