#include<iostream>

using namespace std;

int main() {
    int A,B,V;
    cin>>A>>B>>V;
    
    int Q = A-B;
    
    cout<<int((V-B+Q-1)/(double)Q)<<endl;
    return 0;
}
