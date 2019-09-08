#include<iostream>

using namespace std;

int minValue, maxValue;
int main() {
    int N;
    int num;
    
    cin>>N;
    
    cin>>num;
    maxValue = num;
    minValue = num;
    for (int i = 0 ; i < N-1 ; i++) {
        scanf("%d",&num);
        if (num > maxValue) maxValue = num;
        if (num < minValue) minValue = num;
    }
    
    cout<<minValue<<" "<<maxValue<<endl;
    return 0;
}
