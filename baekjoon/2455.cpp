#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int total = 0;
    int maxValue = 0;
    for(int i=0;i<4;i++){
        int a,b; cin>>a>>b;
        b -= a;
        total += b;
        maxValue = max(total,maxValue);
    }
    cout<<maxValue<<endl;
}