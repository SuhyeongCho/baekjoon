#include<iostream>

using namespace std;

int N,L;

int main(){
    cin>>N>>L;

    for(int i=L;i<=100;i++){
        int tmp = N - i*(i-1)/2;
        if(tmp % i == 0){
            tmp /= i;
            if(tmp < 0) continue;
            for(int j=tmp;j<tmp+i;j++){
                cout<<j<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}