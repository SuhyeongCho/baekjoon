#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int dp[1000001];

int main() {
    int N; cin >> N;
    queue<int> q;
    q.push(N);

    int level = 0;
    dp[N] = INF;
    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0 ; i < siz ; i++) {
            int d = q.front();
            q.pop();

            if (d == 1) {
                cout << level << endl;

                vector<int> v;
                while (d != INF) {
                    v.push_back(d);
                    d = dp[d];
                }
                for (int i = 0 ; i < level + 1 ; i++) {
                    printf("%d ",v.back());
                    v.pop_back();
                }
                cout << endl;
                return 0;
            }

            if (d % 3 == 0) {
                if (!dp[d / 3]) {
                    dp[d / 3] = d;
                    q.push(d / 3);
                }
            }
            
            if (d % 2 == 0) {
                if (!dp[d / 2]) {
                    dp[d / 2] = d;
                    q.push(d / 2);
                }
            }
            if (!dp[d - 1]) {
                dp[d - 1] = d;
                q.push(d - 1);
            }
        }
        level++;
    }
}