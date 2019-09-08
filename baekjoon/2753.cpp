#include<iostream>

using namespace std;

bool isLeap(int year) {
    
    if(year % 400 == 0 || (year % 4 == 0 && year % 100)) return 1;
    else return 0;
}
int main() {
    int year;
    cin>>year;
    cout<<isLeap(year)<<endl;
    return 0;
}
