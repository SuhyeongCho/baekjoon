#include<iostream>

using namespace std;

int N;
int arr[101];

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];

    for(int i=1;i<N;i++){
        int gcdValue = gcd(arr[0],arr[i]);
        cout<<arr[0]/gcdValue<<"/"<<arr[i]/gcdValue<<endl;
    }
    return 0;
}