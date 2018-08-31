#include<iostream>
#include<cstring>

using namespace std;
long long int cache[4000001][4000001];

long long int bin(int n,int r){
    if(r==0||n==r) return 1;
    if(cache[n][r]!=-1) return cache[n][r];
    else return cache[n][r] = (bin(n-1,r-1)+bin(n-1,r))%1000000007;
}
int main(){
    memset(cache, -1, sizeof(cache));
    int N,K;
    cin>>N>>K;
    cout<<bin(N,K)<<'\n';
}
