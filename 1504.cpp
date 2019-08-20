#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector< pair <int, int> > > v(801);

int dijkstra(int start, int end) {
    priority_queue< pair<int,int> > pq;
    vector<int> dist(801, -1);

    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] != -1) continue;

        dist[here] = cost;

        if (here == end) return dist[end];
        for (int i = 0 ; i < v[here].size() ; i++) {
            int next = v[here][i].first;
            int nextCost = v[here][i].second + cost;

            pq.push(make_pair(-nextCost, next));
        }
    }

    return dist[end];
}


int main() {
    int N, E;
    cin >> N >> E;

    for (int i = 0 ; i < E ; i++) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(make_pair(e,w));
        v[e].push_back(make_pair(s,w));

        
    }
    int P1, P2;
    cin >> P1 >> P2;
    
    int p1_p2 = dijkstra(P1, P2);
    int one_p1 = dijkstra(1, P1);
    int one_p2 = dijkstra(1, P2);
    int p1_N = dijkstra(P1, N);
    int p2_N = dijkstra(P2, N);

    int result;
    if (p1_p2 == -1) result = -1;
    else if (  (one_p1 == -1 || p2_N == -1) && (one_p2 == -1 || p1_N == -1)  ) result = -1;
    else if (  (one_p1 == -1 || p2_N == -1) && (one_p2 != -1 && p1_N != -1)  ) result = one_p2 + p1_N + p1_p2;
    else if (  (one_p2 == -1 || p1_N == -1) && (one_p1 != -1 && p2_N != -1)  ) result = one_p1 + p2_N + p1_p2;
    else result = min(one_p1 + p2_N, one_p2 + p1_N) + p1_p2;

    cout << result << endl;

    return 0;
}