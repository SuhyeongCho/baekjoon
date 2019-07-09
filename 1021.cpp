#include<iostream>
#include<list>

using namespace std;


int main(){
    list<int> lt;
    int N,M;
    cin>>N>>M;
    int mArr[M];
    for(int i=0;i<M;i++) cin>>mArr[i];
    for(int i=0;i<N;i++) lt.push_back(i+1);
    int count = 0;
    for(int i=0;i<M;i++){
        int pos = 0;
        for(int j=0;j<lt.size();j++){
            if(lt.front()==mArr[i]){
                pos = j;
            }
            int tmp = lt.front();
            lt.pop_front();
            lt.push_back(tmp);
            
        }
        int mid = lt.size()/2;
        if(pos<=mid){
            for(int j=0;j<pos;j++){
                int tmp = lt.front();
                lt.pop_front();
                lt.push_back(tmp);
                count++;
            }
        }else{
            pos = lt.size() - pos;
            for(int j=0;j<pos;j++){
                int tmp = lt.back();
                lt.pop_back();
                lt.push_front(tmp);
                count++;
            }
        }
        lt.pop_front();
    }
    cout<<count<<endl;
}

