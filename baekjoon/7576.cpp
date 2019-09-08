#include <iostream>
#include <queue>

using namespace std;

struct Position {
    int y;
    int x;
};

int map[1000][1000];
bool isVisited[1000][1000];

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
    int N, M;
    cin >> M >> N;
    int cnt = 0;
    queue<struct Position> q;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                struct Position p = {i, j};
                q.push(p);
            } else if (map[i][j] == 0) {
                cnt++;
            }
        }
    }


    int result = 0;
    while(!q.empty()) {

        if (cnt == 0) {
            cout << result << endl;
            return 0;
        }        
        int siz = q.size();

        for (int i = 0 ; i < siz ; i++) {
            int y = q.front().y;
            int x = q.front().x;
            q.pop();

            if (isVisited[y][x]) continue;
            isVisited[y][x] = true;

            for (int i = 0 ; i < 4 ; i ++) {
                int y1 = y + dir[i][0];
                int x1 = x + dir[i][1];

                if (y1 >= N || x1 >= M || y1 < 0 || x1 < 0) continue;
                if (map[y1][x1] == 0) {
                    map[y1][x1] = 1;
                    struct Position p = {y1, x1};
                    q.push(p);
                    cnt--;
                }
            }
        }
        result++;
    }
    cout << -1 << endl;
    return 0;
}