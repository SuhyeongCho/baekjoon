#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long int n; cin>>n;
    long long int i = 1;
    for(;i<n;i++){
        long long int X = n - ((pow(2,i) - 1) * (i + 1) + i);
        if(X <= (pow(2,i)*(i + 1)))
            break;
    }
    cout<<i<<endl;
}
