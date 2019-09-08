#include <iostream>
#include <vector>

using namespace std;

bool check(int i, int j, int N, int M, vector< vector<bool> > isVisited) {
    if (i < 0) return false;
    if (j < 0) return false;
    if (i >= N) return false;
    if (j >= M) return false;
    if (isVisited[i][j]) return false;
    return true;
}

bool solve(int i, int j, int N, int M, vector< vector<bool> > &isVisited, vector< vector<bool> > map) {
    if (check(i, j, N, M, isVisited)) {
        isVisited[i][j] = true;
        if (map[i][j] == true) {
            solve(i - 1, j, N, M, isVisited, map);
            solve(i + 1, j, N, M, isVisited, map);
            solve(i, j - 1, N, M, isVisited, map);
            solve(i, j + 1, N, M, isVisited, map);
            return true;
        }
        return false;
    } else {
        return false;
    }
}

int main() {
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        int N, M, K;
        cin >> M >> N >> K;
        vector< vector<bool> > isVisited(N, vector<bool>(M, 0));
        vector< vector<bool> > map(N, vector<bool>(M, 0));

        for (int i = 0 ; i < K ; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[b][a] = true;
        }

        int count = 0;
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                if(solve(i, j, N, M, isVisited, map)) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }
    
    return 0;
}