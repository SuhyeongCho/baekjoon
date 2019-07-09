#include<iostream>

using namespace std;

int arr[42];
int main() {
    int count = 0;
    for(int i = 0 ; i < 10 ; i++) {
        int num; cin>>num;
        arr[num % 42]++;
    }
    
    for(int i = 0 ; i < 42 ; i++) {
        if (arr[i]) count++;
    }
    cout<<count<<endl;
}
