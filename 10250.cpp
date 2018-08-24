#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int H,W,N;
        cin>>H>>W>>N;
        int floor  = N%H?N%H:H;
        int num = N%H?N/H+1:N/H;
        int room = floor*100+num;
        cout<<room<<endl;
    }
}
