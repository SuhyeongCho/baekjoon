#include <iostream>
#include <queue>

using namespace std;

bool map[100][100];
bool isVisited[100][100];

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0 ; i < N ; i++) {
        char s[101];
        scanf("%s", s);
        for (int j = 0 ; j < M ; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    queue< pair<int,int> > q;
    q.push(make_pair(0,0));
    int result = 0;
    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0 ; i < siz ; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (isVisited[y][x]) continue;
            isVisited[y][x] = true;

            if (y == N - 1 && x == M - 1) {
                cout << result + 1 << endl;
                return 0;
            }

            if (y - 1 >= 0 && map[y - 1][x]) q.push(make_pair(y - 1, x));
            if (x - 1 >= 0 && map[y][x - 1]) q.push(make_pair(y, x - 1));
            if (y + 1 < N && map[y + 1][x]) q.push(make_pair(y + 1, x));
            if (x + 1 < M && map[y][x + 1]) q.push(make_pair(y, x + 1));

        }
        result++;
    }

    return 0;
}