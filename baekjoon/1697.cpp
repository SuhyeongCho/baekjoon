#include <iostream>
#include <queue>

using namespace std;

bool isVisited[100001];

int main() {
    int N, K; cin >> N >> K;
    queue<int> q;
    q.push(N);

    int result = 0;
    while (!q.empty()) {
        int siz = q.size();
        for (int i = 0 ; i < siz ; i++) {
            int d = q.front(); q.pop();
            
            if (isVisited[d]) continue;
            isVisited[d] = true;

            if (d == K) {
                cout << result << endl;
                return 0;
            }

            if (d - 1 >= 0) q.push(d - 1);
            if (d + 1 <= 100000) q.push(d + 1);
            if (d * 2 <= 100000) q.push(d * 2);
        }
        result++;
    }
    return 0;
}