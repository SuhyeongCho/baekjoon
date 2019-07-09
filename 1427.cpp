#include<iostream>

using namespace std;
int arr[10];

int main(){
    int n; cin>>n;
    while(n){
        arr[n%10]++;
        n/=10;
    }
        
    
    for(int i=9;i>=0;i--){
        for(int j=0;j<arr[i];j++){
            printf("%d",i);
        }
    }
    printf("\n");

    return 0;
}
