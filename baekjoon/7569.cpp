#include <iostream>
#include <queue>

using namespace std;

struct Position {
    int z;
    int y;
    int x;
};

int map[100][100][100];
bool isVisited[100][100][100];

int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int main() {
    int N, M, H;
    cin >> M >> N >> H;
    int cnt = 0;
    queue<struct Position> q;
    for (int k = 0 ; k < H ; k++) {
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                scanf("%d", &map[k][i][j]);
                if (map[k][i][j] == 1) {
                    struct Position p = {k, i, j};
                    q.push(p);
                } else if (map[k][i][j] == 0) {
                    cnt++;
                }
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
            int z = q.front().z;
            int y = q.front().y;
            int x = q.front().x;
            q.pop();

            if (isVisited[z][y][x]) continue;
            isVisited[z][y][x] = true;

            for (int i = 0 ; i < 6 ; i ++) {
                int z1 = z + dir[i][0];
                int y1 = y + dir[i][1];
                int x1 = x + dir[i][2];

                if (z1 >= H || y1 >= N || x1 >= M || z1 < 0 || y1 < 0 || x1 < 0) continue;
                if (map[z1][y1][x1] == 0) {
                    map[z1][y1][x1] = 1;
                    struct Position p = {z1, y1, x1};
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