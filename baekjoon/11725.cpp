#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main () {
    int N ; cin >> N;
    vector<int> node[N + 1];

    for (int i = 0 ; i < N - 1 ; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        node[s].push_back(e);
        node[e].push_back(s);
    }

    vector<int> parent(N + 1);
    vector<bool> isVisited(N + 1);
    queue<int> q;

    q.push(1);
    while(!q.empty()) {
        int d = q.front();
        q.pop();

        isVisited[d] = true;

        for (int i = 0 ; i < node[d].size() ; i++) {
            int child = node[d][i];
            if (isVisited[child]) continue;
            parent[child] = d;
            q.push(child);
        }
    }

    for (int i = 2; i <= N ; i++) {
        printf("%d\n",parent[i]);
    }
    return 0;
}