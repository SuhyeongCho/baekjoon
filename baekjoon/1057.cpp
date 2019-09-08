#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N,a,b;
    cin>>N>>a>>b;

    a--;b--;

    int cnt = 0;
    while(a!=b){
        a /= 2;
        b /= 2;
        cnt++;
    }
    
    cout<<cnt<<endl;
}