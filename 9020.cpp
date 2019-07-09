#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num){
    if(num==1) return 0;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return 0;
    }
    return 1;
}

void goldBach(int num){
    int half = num/2;
    for(int i=half;i>1;i--){
        if(isPrime(i)){
            int g = num-i;
            if(isPrime(g)){
                cout<<i<<" "<<g<<'\n';
                return;
            }
        }
    }
}

int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int num; cin>>num;
        goldBach(num);
    }
    return 0;
}
