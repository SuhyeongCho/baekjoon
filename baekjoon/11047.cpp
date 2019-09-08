#include <iostream>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    
    int arr[11] = {0,};
    
    for (int i = 1; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }
    
    int i = N;
    int count = 0;
    while (K) {
        if (arr[i] > K) i--;
        else {
            K -= arr[i];
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
