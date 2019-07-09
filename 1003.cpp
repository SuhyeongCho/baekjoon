#include <iostream>

using namespace std;
int zero[41] = {1,0,};
int one[41] = {0,1,};
void fibonacci(int n) {
    zero[n] = zero[n-1]+zero[n-2];
    one[n] = one[n-1]+one[n-2];
}

int main(){
    int T; cin>>T;
    for(int i=2;i<41;i++) fibonacci(i);
    for(int t=0;t<T;t++){
        int num; cin>>num;
        cout<<zero[num]<<" "<<one[num]<<'\n';
    }
}
