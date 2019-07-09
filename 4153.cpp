#include<iostream>

using namespace std;

int main() {
    
    while(true) {
        int a,b,c;
        cin>>a>>b>>c;
        
        if (!a && !b && !c) break;
        a *= a;
        b *= b;
        c *= c;
        
        if (a + b == c || b + c == a || a + c == b) cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
    }
    
    return 0;
}
