#include <iostream>
#include <string>

using namespace std;

int arr[64][64];
string s;

bool findOneQuadTree(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 0) return 0;
        }
    }
    return 1;
}

bool findZeroQuadTree(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 1) return 0;
        }
    }
    return 1;
}

void solve(int n, int startY, int startX) {
    if (n == 0) return;
    
    if (findOneQuadTree(n, startY, startX)) s += "1";
    else if (findZeroQuadTree(n, startY, startX)) s += "0";
    else {
        int m = n / 2;
        s += "(";
        solve(m, startY, startX);
        solve(m, startY, startX + m);
        solve(m, startY + m, startX);
        solve(m, startY + m, startX + m);
        s += ")";
    }
    return;
}

int main() {
    int N; cin >> N;

    for (int i = 0 ; i < N ; i++) {
        string tmp; cin >> tmp;
        for (int j = 0 ; j < N ; j++) {
            arr[i][j] = tmp[j] - '0';
        }
    }
    solve(N, 0, 0);

    cout << s << endl;
    return 0;
}