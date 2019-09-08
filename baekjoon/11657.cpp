#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    bool flag = false;
    vector< vector< pair<int, int> > > v(N + 1);
    for (int i = 0 ; i < M ; i++) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(make_pair(e,w));
    }

    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    for (int i = 1 ; i <= N ; i++) {
        for (int start = 1; start <= N ; start++ ) {
            for (int j = 0 ; j < v[start].size() ; j++) {
                int here = v[start][j].first;
                int cost = v[start][j].second;

                if (dist[start] != INF && dist[here] > dist[start] + cost) {
                    dist[here] = dist[start] + cost;
                    if (i == N) flag = true;
                }
            }
        }
    }

    if (flag) printf("-1\n");
    else {
        for (int i = 2 ; i <= N ; i++) {
            if (dist[i] == INF) printf("-1\n");
            else printf("%d\n",dist[i]);
        }
    }

    return 0;
}