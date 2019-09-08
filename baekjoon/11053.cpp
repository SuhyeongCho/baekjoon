#include<iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main(){
    int N; cin >> N;
    
    for( int i = 1 ; i <= N ; i++ ){
        scanf("%d", &arr[i]);
    }
    
    for ( int i = 1; i <= N ; i++ ) {
        dp[i] = 1;
        for ( int j = 1 ; j < i ; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    
    int maxValue = 0;
    for ( int i = 1 ; i <= N ; i++) {
        if (maxValue < dp[i]) {
            maxValue = dp[i];
        }
    }
    
    cout << maxValue << endl;
   
    return 0;
}
