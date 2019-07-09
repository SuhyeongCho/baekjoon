#include<iostream>
#include<algorithm>

using namespace std;

int N,K;
int arr[5000000];
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);

    sort(arr,arr+N);
    cout<<arr[K-1]<<endl;
    return 0;
}