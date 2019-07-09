#include<iostream>

using namespace std;

int main() {
    int index = 0, maxValue = 0;
    
    for(int i = 0 ; i < 9 ; i++) {
        int num; cin>>num;
        if(maxValue < num) {
            maxValue = num;
            index = i + 1;
        }
    }
    
    cout<<maxValue<<endl;
    cout<<index<<endl;
    return 0;
}
