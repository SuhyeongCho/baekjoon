#include<iostream>

using namespace std;

int reverseInt(int num){
    int result = 0;
    while(num){
        result *= 10;
        result += num%10;
        num /=10;
    }
    return result;
}
int main(){
    int a,b;
    cin>>a>>b;
    int ra = reverseInt(a);
    int rb = reverseInt(b);
    cout<<max(ra,rb);
}
