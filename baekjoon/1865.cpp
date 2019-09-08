#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int main() {
    int T; cin >> T;
    for (int ttt = 0 ; ttt < T ; ttt++) {
        int N, M, W;
        cin >> N >> M >> W;

        vector< vector<pair<int, int> > > v(N + 1);
        vector<int> dist(N + 1 ,INF);
        bool flag = false;
        for (int i = 0 ; i < M ; i++) {
            int s, e, w;
            scanf("%d %d %d", &s, &e, &w);
            v[s].push_back(make_pair(e,w));
            v[e].push_back(make_pair(s,w));

        }
        for (int i = 0 ; i < W ; i++) {
            int s, e, w;
            scanf("%d %d %d", &s, &e, &w);
            v[s].push_back(make_pair(e,-w));
        }

        dist[1] = 0;
        for (int start = 1 ; start <= N ; start++) {
            for (int i = 1 ; i <= N ; i++) {
                for (int j = 0 ; j < v[i].size() ; j++) {
                    int here = v[i][j].first;
                    int cost = v[i][j].second;
                    if (dist[i] != INF && dist[here] > dist[i] + cost) {
                        dist[here] = dist[i] + cost;
                        if (start == N) flag = true;
                    }
                }
            }
        }

        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}