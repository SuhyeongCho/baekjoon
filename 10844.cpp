#include<iostream>

using namespace std;

int dp[10] = {0,1,1,1,1,1,1,1,1,1};
int tmp[10];
int main(){
    int N; cin >> N;
    
    for ( int i = 0 ; i < N - 1 ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++) {
            if ( j == 0 ) tmp[j] = dp[j + 1];
            else if ( j == 9 ) tmp[j] = dp[j - 1];
            else tmp[j] = ( dp[j - 1] + dp [j + 1] ) % 1000000000;
        }
        
        for ( int j = 0 ; j < 10 ; j++) {
            dp[j] = tmp[j];
        }
    }
    
    
    long long int sum = 0;
    
    for ( int i = 0 ; i < 10 ; i++) {
        sum = ( sum + dp[i]) % 1000000000;
    }
    
    cout << sum <<endl;
    
    return 0;
}
