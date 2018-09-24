#include<iostream>
using namespace std;

int factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);
}
int diffSum(int data[],int n){
    int sum = 0;
    for(int i=0;i<n-1;i++){
        int diff = abs(data[i+1]-data[i]);
        sum += diff;
    }
    return sum;
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
void sort(int data[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(data[j]>data[j+1])
                swap(data[j],data[j+1]);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int data[N];
    for(int i=0;i<N;i++){cin>>data[i];}
    sort(data,N);
    int size = factorial(N);
    int Max = 0;
    for(int i=0;i<size;i++){
        Max = max(diffSum(data,N),Max);
        perm(data,N);
    }
    cout<<Max<<endl;
    return 0;
}


