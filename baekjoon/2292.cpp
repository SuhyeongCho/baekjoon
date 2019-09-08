#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    int sum = 1;
    int result = 0;
    for(int i=0;i<n;i++){
        sum = sum + i*6;
        if(sum >= n){
            result = 1 + i;
            break;
        }
    }
    cout<<result;
}
