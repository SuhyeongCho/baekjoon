#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool isVisited[25][25];
bool map[25][25];

bool check(int i, int j) {
    if (i < 0) return false;
    if (j < 0) return false;
    if (i >= N) return false;
    if (j >= N) return false;
    if (isVisited[i][j]) return false;
    return true;
}

void solve(int i, int j, int &count) {
    if (check(i, j)) {
        isVisited[i][j] = true;
        if (map[i][j] == 1) {
            count++;
            solve(i - 1, j, count);
            solve(i + 1, j, count);
            solve(i, j - 1, count);
            solve(i, j + 1, count);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        char s[N + 1];
        scanf("%s", s);
        for (int j = 0 ; j < N ; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    vector<int> v;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            int d = 0;
            solve(i, j, d);
            if (d > 0) v.push_back(d);
        }
    }


    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0 ; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}