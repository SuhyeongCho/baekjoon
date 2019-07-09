
#include<iostream>
#include<algorithm>
using namespace std;

long long int factorial[17];

int N;
int **W;


bool check(int data[]){
    for(int i=0;i<N-1;i++){
        if(W[data[i]][data[i+1]] == 0)
            return false;
    }
    if(W[data[N-1]][data[0]] == 0)
        return false;
    return true;
}

void perm(int data[],int n){
    int k=-1,l=-1;
    for(int i=0;i<n-1;i++)
        if(data[i]<data[i+1]) k = i;
    if(k == -1){
        return;
    }
    for(int i=k+1;i<n;i++)
        if(data[k]<data[i]) l = i;
    swap(data[k],data[l]);
    int tmp[n-k-1];
    for(int i=n-1,j=0;i>k;i--,j++) tmp[j] = data[i];
    for(int i=k+1;i<n;i++) data[i] = tmp[i-k-1];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    cin>>N;
    W = new int*[N];
    for(int i=0;i<N;i++){
        W[i] = new int[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>W[i][j];
        }
    }
    
    factorial[0] = 1;
    for(int i=1;i<=16;i++){
        factorial[i] = factorial[i-1]*i;
    }
    
    int data[N];
    
    for(int i=0;i<N;i++){
        data[i] = i;
    }
    
    int result = 2147483647;
    
    for(long long int i=0;i<factorial[N];i++,perm(data,N)){
        //        for(int j=0;j<N;j++) cout<<data[j];
        //        cout<<endl;
        
        if(!check(data)) continue;
        
        int d = 0;
        for(int i=0;i<N-1;i++){
            d += W[data[i]][data[i+1]];
        }
        d += W[data[N-1]][data[0]];
        //        cout<<"d : "<<d<<endl;
        result = min(result,d);
        
    }
    cout<<result<<endl;
    return 0;
}


