#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    bool arr[50][50];
    
    for (int i = 0 ; i < N ; i++) {
        string s; cin >>s;
        for (int j = 0 ; j < M ; j++) {
            if (s[j] == 'W') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    
    
    int result = 64;
    for (int i = 0 ; i <= N - 8 ; i++) {
        for (int j = 0 ; j <= M - 8 ; j++) {
            int whiteCount = 0, blackCount = 0;
            for (int i1 = i ; i1 < i + 8 ; i1++) {
                for (int j1 = j; j1 < j + 8 ; j1++) {
                    if ((i1 + j1) % 2) {
                        if(arr[i1][j1] == 1) whiteCount++;
                    } else {
                        if(arr[i1][j1] == 0) blackCount++;
                    }
                }
            }

            int sum = whiteCount + blackCount;
            result = min(result, min(sum, 64 - sum));
        }
    }
    cout << result << endl;
    return 0;
}
