#include<iostream>

using namespace std;

int N,M;
int arr[100];

int main() {
    cin >> N >> M;
    
    for (int i = 0 ; i < N ; i++) {
        cin>>arr[i];
    }
    
    int result = 0;
    
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (i == j) continue;
            for (int k = 0 ; k < N ; k++) {
                if (i == k || j == k) continue;
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= M && M - sum < M - result) {
                    result = sum;
                }
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
