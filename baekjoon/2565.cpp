#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector< pair<int, int> > v;
int dp[101];

int main() {
    int N; cin >> N;
    
    
    for (int i = 0; i < N ; i++) {
        int a, b; scanf("%d %d", &a,&b);
        v.push_back(make_pair(a,b));
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0 ; i < N ; i++) {
        dp[i] = 1; dp[i] = 1;
        for (int j = 0 ; j < i ; j++) {
            if (v[i].second > v[j].second) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int maxValue = 0;
    for (int i = 0 ; i < N ; i++) {
        if (maxValue < dp[i]) {
            maxValue = dp[i];
        }
    }
    
    cout << N - maxValue << endl;
}
