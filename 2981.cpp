#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int N;
int arr[101];
int b[101];
int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr,arr+N);
    for(int i=0;i<N-1;i++){
        b[i] = arr[i+1] - arr[i];
    }

    int gcdValue = b[0];
    for(int i=1;i<N-1;i++){
        gcdValue = gcd(gcdValue,b[i]);
    }

    set<int> s;
    for(int i=2;i*i<=gcdValue;i++){
        if(gcdValue % i == 0){
            s.insert(i);
            s.insert(gcdValue/i);
        }
    }
    s.insert(gcdValue);

    set<int>::iterator iter;
    for(iter = s.begin();iter!=s.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;

    return 0;
}