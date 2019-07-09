#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    int sum = 0;
    for(int i=1;i<n;i++){
        sum = sum + i;
        if(sum>=n){
            int m = sum-n;
            if(i%2==0)cout<<i-m<<'/'<<m+1<<endl;
            else cout<<m+1<<'/'<<i-m<<endl;
            break;
        }
    }
}
