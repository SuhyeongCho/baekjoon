#include<iostream>

using namespace std;

int main() {
    int hour,min;
    
    cin>>hour>>min;
    
    int total = hour*60 + min;
    
    total = total - 45;
    
    total += 24*60;
    total %= 24 * 60;
    
    hour = total / 60;
    min = total % 60;
    
    cout<<hour<<" "<<min<<endl;
    
    return 0;
}
