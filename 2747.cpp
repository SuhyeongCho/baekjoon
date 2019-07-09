#include<iostream>

using namespace std;

long long int fi[50];
long long int fibbo(int num){
    long long int &des = fi[num];
    if(des!=-1) return des;
    else return des = fibbo(num-1) + fibbo(num-2);
    
}
int main(){
    int num; cin>>num;
    for(int i=0;i<50;i++) fi[i] = -1;
    fi[0] = 0; fi[1] = 1;
    cout<<fibbo(num)<<'\n';
}
