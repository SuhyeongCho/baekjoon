#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++) arr[i] = 1;
        for(int i=0;i<k;i++){
            for(int j=n-2;j>=0;j--){
                arr[j] += arr[j+1];
            }
        }
        int result=0;
        for(int i=0;i<n;i++) result += arr[i];
        cout<<result<<endl;
    }
}
