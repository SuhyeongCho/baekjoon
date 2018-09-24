#include<iostream>
using namespace std;

int factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);
}
void perm(int data[],int n){
    int k=-1,l=-1;
    for(int i=0;i<n-1;i++)
        if(data[i]<data[i+1]) k = i;
    if(k == -1){
        cout<<-1<<'\n';
        return;
    }
    for(int i=k+1;i<n;i++)
        if(data[k]<data[i]) l = i;
    swap(data[k],data[l]);
    int tmp[n-k-1];
    for(int i=n-1,j=0;i>k;i--,j++) tmp[j] = data[i];
    for(int i=k+1;i<n;i++) data[i] = tmp[i-k-1];
    
    for(int i=0;i<n;i++) cout<<data[i]<<" ";
    cout<<'\n';
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int data[N];
    for(int i=0;i<N;i++){data[i] = i+1;cout<<data[i]<<" ";}
    cout<<'\n';
    int size = factorial(N);
    for(int i=0;i<size-1;i++)
        perm(data,N);
    return 0;
}

