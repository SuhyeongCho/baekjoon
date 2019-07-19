#include<iostream>

using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];
int main(){
    int N; cin >> N;
    
    for( int i = 1 ; i <= N ; i++ ){
        scanf("%d", &arr[i]);
    }
    
    for( int i = 1 ; i <= N ; i++ ) {
        dp1[i] = 1;
        for ( int j = 1 ; j < i ; j++ ) {
            if (arr[i] > arr[j]) {
                if (dp1[i] < dp1[j] + 1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }
    }
    
    for( int i = N ; i > 0 ; i-- ) {
        dp2[i] = 1;
        for ( int j = N ; j > i ; j-- ) {
            if (arr[i] > arr[j]) {
                if (dp2[i] < dp2[j] + 1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }
    }
    
    int maxValue = 0;
    for (int i = 1 ; i <= N ; i++ ) {
        if (dp1[i] + dp2[i] > maxValue) {
            maxValue = dp1[i] + dp2[i];
        }
    }
    maxValue--;
    
    cout << maxValue << endl;
    
   
    return 0;
}

