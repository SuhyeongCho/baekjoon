#include<iostream>

using namespace std;

bool isPrime(int num){
    if(num==1) return 0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return 0;
    }
    return 1;
}

int main(){
    int M,N;
    cin>>M>>N;
    int sum = 0;
    int min = 0;
    int count = 0;
    for(int i=M;i<=N;i++){
        if(isPrime(i)){
            count++;
            if(count==1) min = i;
            sum += i;
        }
    }
    if(count)cout<<sum<<endl<<min<<endl;
    else cout<<-1<<endl;
    return 0;
}
