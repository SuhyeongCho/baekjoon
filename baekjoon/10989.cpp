#include<iostream>

using namespace std;
int arr[10001];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int d; scanf("%d",&d);
        arr[d]++;
    }
        
    
    for(int i=1;i<=10000;i++){
        for(int j=0;j<arr[i];j++){
            printf("%d\n",i);
        }
    }

    return 0;
}
