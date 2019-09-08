#include<iostream>
#include<algorithm>

using namespace std;

int N;
bool cup[3];

int main(){
    cin>>N;
    cup[0] = 1;
    for(int i=0;i<N;i++){
        int a,b; cin>>a>>b;
        swap(cup[a-1],cup[b-1]);
    }
    if(cup[0] == 1) cout<<1<<endl;
    else if(cup[1] == 1) cout<<2<<endl;
    else cout<<3<<endl;

    return 0;
}