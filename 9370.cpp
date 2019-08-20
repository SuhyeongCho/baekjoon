#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector< pair<int, int> > > v(2001);
vector< vector<int> > dist(3, vector<int>(2001));

void dijkstra(int candidate, int start) {
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[candidate][here] != -1) continue;
        dist[candidate][here] = cost;

        for (int i = 0 ; i < v[here].size() ; i++) {
            int next = v[here][i].first;
            int nextCost = v[here][i].second + cost;

            pq.push(make_pair(-nextCost, next));
        }
    }
}


int main() {

    int T; cin >> T;
    for (int ttt = 0 ; ttt < T ; ttt++) {

        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        for (int i = 0 ; i < 2001 ; i++) {
            v[i].clear();
            dist[0][i] = -1;        
            dist[1][i] = -1;
            dist[2][i] = -1;
        }

        for (int i = 0 ; i < m ; i++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            v[a].push_back(make_pair(b, d));
            v[b].push_back(make_pair(a, d));
        }

        vector<int> candidates(t);
        for (int i = 0 ; i < t ; i++) {
            scanf("%d", &candidates[i]);
        }

        dijkstra(0, s);
        dijkstra(1, g);
        dijkstra(2, h);

        vector<int> result;
        for (int i = 0 ; i < t ; i++) {
            if (dist[0][candidates[i]] == dist[0][g] + dist[1][h] + dist[2][candidates[i]] || dist[0][candidates[i]] == dist[0][h] + dist[2][g] + dist[1][candidates[i]]) {
                result.push_back(candidates[i]);
            }
        }

        sort(result.begin(), result.end());
        for (int i = 0 ; i < result.size() ; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}