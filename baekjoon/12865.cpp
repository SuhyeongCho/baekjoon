#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][100001];

int main() {
    int N, K; cin >> N >> K;
    vector<pair<int,int> > v;

    v.push_back(make_pair(0,0));

    for (int i = 1 ; i <= N ; i++) {
        int w, p;
        scanf("%d %d", &w, &p);
        v.push_back(make_pair(w,p));
    }

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 0 ; j <= K ; j++) {
            if (v[i].first <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}