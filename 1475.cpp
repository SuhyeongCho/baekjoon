#include<iostream>

using namespace std;

int main(){
    int N; cin>>N;
    int arr[10] = {0};
    if(N==0){
        cout<<1<<endl;
        return 0;
    }
    while(N){
        arr[N%10]++;
        N /= 10;
    }
    arr[6] += arr[9];
    if(arr[6]%2) arr[6] = arr[6]/2 +1;
    else arr[6] = arr[6]/2;
    
    int max = 0;
    for(int i=0;i<9;i++){
        if(arr[i]>arr[max]) max = i;
    }
    cout<<arr[max]<<endl;
}
