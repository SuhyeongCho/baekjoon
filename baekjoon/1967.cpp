#include <iostream>
#include <vector>

using namespace std;

vector<vector< pair<int,int> > > v(10001);
bool isVisited[10001];

int maxValue;
int maxPos;

void dfs(int pos, int value) {

    if (value > maxValue) {
        maxValue = value;
        maxPos = pos;
    }

    for (int i = 0 ; i < v[pos].size() ; i++) {
        int next = v[pos][i].first;
        int cost = v[pos][i].second;
        if (isVisited[next]) continue;

        isVisited[next] = true;
        dfs(next, value + cost);
    }
}

int main() {
    int N; cin >> N;

    for (int i = 0 ; i < N - 1 ; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        v[start].push_back(make_pair(end, weight));
        v[end].push_back(make_pair(start, weight));

    }

    maxPos = 1;
    maxValue = 0;

    isVisited[1] = true;
    dfs(maxPos, 0);

    for (int i = 0 ; i < 10001 ; i++) {
        isVisited[i] = false;
    }

    maxValue = 0;

    isVisited[maxPos] = true;
    dfs(maxPos, 0);

    cout << maxValue << endl;
    return 0;
}