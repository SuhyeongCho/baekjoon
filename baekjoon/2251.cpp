#include<iostream>
#include<queue>
#include<set>

using namespace std;

struct Water{
    int a;
    int b;
    int c;
};

int MAX_A;
int MAX_B;
int MAX_C;

bool isVisited[200][200][200];

int main(){
    cin>>MAX_A>>MAX_B>>MAX_C;
    
    struct Water init = {0,0,MAX_C};
    
    queue<struct Water> q;
    set<int> result;
    
    q.push(init);
    
    while(!q.empty()){
        int siz = q.size();
        for(int i=0;i<siz;i++){
            struct Water d = q.front();
            q.pop();
            
//            cout<<d.a<<" "<<d.b<<" "<<d.c<<" "<<endl;
            
            
            if(isVisited[d.a][d.b][d.c]) continue;
            
            isVisited[d.a][d.b][d.c] = true;
            
            if(d.a == 0){
                result.insert(d.c);
            }
            
            if(d.a != 0){
                struct Water new1 = d;
                if(d.a + d.b <= MAX_B){
                    new1.a = 0;
                    new1.b = d.a + d.b;
                }
                else{
                    new1.a = d.a + d.b - MAX_B;
                    new1.b = MAX_B;
                }
                q.push(new1);
                struct Water new2 = d;
                if(d.a + d.c <= MAX_C){
                    new2.a = 0;
                    new2.c = d.a + d.c;
                }
                else{
                    new2.a = d.a + d.c - MAX_C;
                    new2.c = MAX_C;
                }
                q.push(new2);
            }
            
            if(d.b != 0){
                struct Water new1 = d;
                if(d.b + d.a <= MAX_A){
                    new1.b = 0;
                    new1.a = d.b + d.a;
                }
                else{
                    new1.b = d.b + d.a - MAX_A;
                    new1.a = MAX_A;
                }
                q.push(new1);
                struct Water new2 = d;
                if(d.b + d.c <= MAX_C){
                    new2.b = 0;
                    new2.c = d.b + d.c;
                }
                else{
                    new2.b = d.b + d.c - MAX_C;
                    new2.c = MAX_C;
                }
                q.push(new2);
            }
            
            if(d.c != 0){
                struct Water new1 = d;
                if(d.c + d.a <= MAX_A){
                    new1.c = 0;
                    new1.a = d.c + d.a;
                }
                else{
                    new1.c = d.c + d.a - MAX_A;
                    new1.a = MAX_A;
                }
                q.push(new1);
                struct Water new2 = d;
                if(d.c + d.b <= MAX_B){
                    new2.c = 0;
                    new2.b = d.c + d.b;
                }
                else{
                    new2.c = d.c + d.b - MAX_B;
                    new2.b = MAX_B;
                }
                q.push(new2);
            }
            
        }
    }
    
    set<int>::iterator iter;
    for(iter=result.begin();iter!=result.end();++iter){
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
