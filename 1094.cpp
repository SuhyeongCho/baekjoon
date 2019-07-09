#include <iostream>

using namespace std;

int N;
int main(){
    cin>>N;
    int result = 0;
    while(N){
        result += N%2;
        N /= 2;
    }
    cout<<result<<endl;
}