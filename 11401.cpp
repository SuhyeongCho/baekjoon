#include<iostream>
#define MOD 1000000007

using namespace std;

int N,K;

long long int pow(long long int a){
    bool bin[32] = {1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0};
    long long int x[32];
    x[0] = a;
    for(int i=1;i<32;i++){
        x[i] = (x[i-1]*x[i-1])%MOD;
    }
    long long int result = 1;
    for(int i=0;i<32;i++){
        if(bin[i]){
            result  = (result *x[i])%MOD;
        }
    }
    return result;
}

long long int fac[4000001];
int main(){
    cin>>N>>K;
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<=N;i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }
    long long int A = fac[N];
    long long int B = pow(fac[K]);
    long long int C = pow(fac[N-K]);

    cout<<(((A*B)%MOD)*C)%MOD<<endl;
    return 0;
}
