#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
bool isVisited[1001];
vector< vector <int> > v(1001,vector<int>(1001,0));

void dfs(int pos) {
    if (isVisited[pos]) return;
    printf("%d ", pos);
    isVisited[pos] = true;
    for (int i = 1 ; i <= N; i++) {
        if (v[pos][i]) dfs(i);
    }
}

void bfs(int pos) {
    queue<int> q;
    q.push(pos);
    while(!q.empty()) {
        int d = q.front();
        q.pop();
        if (!isVisited[d]) {
            printf("%d ", d);
            isVisited[d] = true;
            for (int i = 1 ; i <= N ; i++) {
                if (v[d][i]) q.push(i);
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;

    for (int i = 0 ; i < M ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }

    for (int i = 1 ; i <= 1000 ; i++) {
        isVisited[i] = false;
    }
    dfs(V);
    cout << endl;

    for (int i = 1 ; i <= 1000 ; i++) {
        isVisited[i] = false;
    }
    bfs(V);
    cout << endl;

    return 0;
}

