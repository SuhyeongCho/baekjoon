#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N; cin >> N;
    int arr[101] = {0,};
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1 ; i < N ; i++) {
        int value = gcd(arr[0], arr[i]);
        
        int first = arr[0] / value;
        int second = arr[i] / value;
        
        printf("%d/%d\n", first, second);
    }
    
    return 0;
}
