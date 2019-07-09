#include<iostream>

using namespace std;

int N;
int cnt;
int *col;

bool promise(int n){
    for(int i=0;i<n;i++){
        if(col[i]==col[n] || abs(col[i]-col[n])==abs(n-i)){
            return false;
        }
    }
    return true;
}
void queen(int n){
    if(promise(n)){
        if(n==N-1){
            cnt++;
        }
        else{
            for(int i=0;i<N;i++){
                col[n+1] = i;
                queen(n+1);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    col = new int[N];
    cnt = 0;
    for(int i=0;i<N;i++){
        col[0] = i;
        queen(0);
    }
    cout<<cnt<<endl;
    
    return 0;
}





