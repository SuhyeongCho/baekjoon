#include <iostream>
#include <vector>

using namespace std;

vector<vector< pair<int,int> > > v(100001);
bool isVisited[100001];

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

    for (int i = 0 ; i < N ; i++) {
        int start;
        scanf("%d", &start);
        while(1) {
            int child, weight;
            scanf("%d", &child);
            if (child == -1) break;
            scanf("%d", &weight);

            v[start].push_back(make_pair(child, weight));
            v[child].push_back(make_pair(start, weight));
        }
    }

    maxPos = 1;
    maxValue = 0;

    isVisited[1] = true;
    dfs(maxPos, 0);


    for (int i = 0 ; i < 100001 ; i++) {
        isVisited[i] = false;
    }

    maxValue = 0;

    isVisited[maxPos] = true;
    dfs(maxPos, 0);

    cout << maxValue << endl;
    return 0;
}