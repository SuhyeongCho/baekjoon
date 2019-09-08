#include<iostream>

using namespace std;

int main() {
    int N; cin>>N;
    
    int result = 0;
    
    for(int i = N ; i > 0 ; i--) {
        int num = i;
        int sum = i;
        
        while (num) {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        
        if (sum == N) result = i;
    }
    
    cout << result << endl;
    return 0;
    
}
