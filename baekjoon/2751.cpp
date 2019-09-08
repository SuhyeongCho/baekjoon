#include<iostream>
#include<algorithm>



using namespace std;
short arr[1000001];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    
    
    for(int i=0;i<n;i++) printf("%d\n",arr[i]);
    return 0;
}
