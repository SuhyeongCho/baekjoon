#include<iostream>

using namespace std;

int M,N;
int main() {
    
    cin>>M>>N;
    int a,b,c;
    
    a = N/100;
    N %= 100;
    
    b = N/10;
    N %= 10;
    
    c = N;
    
    cout<<M * c<<endl;
    cout<<M * b<<endl;
    cout<<M * a<<endl;
    cout<<M * c + M * b * 10 + M * a * 100<<endl;
    
    return 0;
}
