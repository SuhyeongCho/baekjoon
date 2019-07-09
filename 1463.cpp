#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;


queue<int> q;
int X;
int main(){
    cin>>X;
    q.push(X);
    long long int cnt = 0;
    while(!q.empty()){
        int siz = q.size();
        for(int i=0;i<siz;i++){
            int d = q.front();
            q.pop();
            
            if(d == 1){
                cout<<cnt<<endl;
                return 0;
            }
            
            if(d % 2 == 0) q.push(d/2);
            if(d % 3 == 0) q.push(d/3);
            q.push(d - 1);

        }
        cnt++;
    }
    return 0;
}
