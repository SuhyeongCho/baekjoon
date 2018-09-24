#include<iostream>
using namespace std;

long long factorial(int n){
    if(n<=1) return 1;
    return (n*factorial(n-1));
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
    
}
//
//int findPerm(int data[],int size,int K){
//    int orginal[K];
//    for(int i=0;i<K;i++) orginal[i] = i+1;
//    for(int i=0;i<size;i++){
//        bool check = true;
//        for(int j=0;j<K;j++){
//            if(data[j]!=orginal[j]){
//                check = false; break;
//            }
//        }
//        if(check) return i;
//        perm(orginal,K);
//    }
//}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int data[N];
    for(int i=0;i<N;i++) data[i] = i+1;
    int num; cin>>num;
    if(num==1){
        long long k; cin>>k;
        for(long long i=0;i<k-1;i++){
            perm(data,N);
        }
        for(int i=0;i<N;i++) cout<<data[i]<<" ";
        cout<<'\n';
    }
    else if(num==2){
        int find[N];
        long long size = 0;
        for(int i=0;i<N;i++) cin>>find[i];
        for(int i=0;i<N;i++){
            size += (find[i]-1-i)*factorial(N-i-1);
        }
        cout<<size<<'\n';
    }
    return 0;
}



