#include <iostream>

using namespace std;

int N;
bool map[100][100];
bool isVisited[100];

void solve(int pos, int &count) {
    if (isVisited[pos]) return;
    isVisited[pos] = true;
    count++;
    for (int i = 0 ; i < N ; i++) {
        if (map[pos][i]) solve(i, count);
    }
}
int main() {
    int M;
    cin >> N >> M;
    for (int i = 0 ; i < M ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    int count = 0;
    solve(1, count);
    cout << count - 1 << endl;
    return 0;
}