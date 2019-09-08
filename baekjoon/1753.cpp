#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main () {
    int V, E;
    int start;

    cin >> V >> E >> start;

    vector< vector<pair<int, int> > > v(V + 1);
    vector<int> dist(V + 1, -1);
    for (int i = 0 ; i < E ; i++) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(make_pair(e, w));
    }

    priority_queue<pair<int,int> > pq;

    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -1 * pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] != -1) continue;

        dist[here] = cost;

        for (int i = 0 ; i < v[here].size(); i++) {
            int next = v[here][i].first;
            int nextCost = v[here][i].second + cost;

            pq.push(make_pair(-nextCost, next));
        }

    }

    for (int i = 1 ; i <= V ; i++) {
        if (dist[i] == -1) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}