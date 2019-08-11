#include <iostream>
#include <queue>

using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool map[1001][1001];
bool isVisited[1001][1001][2];

struct Position {
    int y;
    int x;
    int isBreak;
};

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0 ; i < N ; i++) {
        char s[1002];
        scanf("%s", s);
        for (int j = 0 ; j < M ; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    queue<struct Position> q;
    struct Position p = {0, 0, 0};
    q.push(p);

    int result = 0;
    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0 ; i < siz ; i++) {
            int y = q.front().y;
            int x = q.front().x;
            int isBreak = q.front().isBreak;
            q.pop();

            if (y == N - 1 && x == M - 1) {
                cout << result + 1 << endl;
                return 0;
            }

            if (isVisited[y][x][isBreak]) continue;
            isVisited[y][x][isBreak] = true;

            for (int d = 0 ; d < 4 ; d++) {
                int y1 = y + dir[d][0];
                int x1 = x + dir[d][1];

                if (y1 < 0 || x1 < 0 || y1 >= N || x1 >= M) continue;

                if (isBreak) {
                    if (map[y1][x1] == 0) {
                        struct Position p = {y1, x1, 1};
                        q.push(p);
                    }
                } else {
                    if (map[y1][x1] == 0) {
                        struct Position p = {y1, x1, 0};
                        q.push(p);
                    } else {
                        struct Position p = {y1, x1, 1};
                        q.push(p);
                    }
                }
            }
        }
        result++;
    }
    cout << -1 << endl;
    return 0;
}