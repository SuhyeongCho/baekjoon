#include <iostream>

using namespace std;

int arr[2187][2187];

int minusOneCount = 0;
int zeroCount = 0;
int oneCount = 0;

bool findOneQuadTree(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 0 || arr[i][j] == -1) return 0;
        }
    }
    return 1;
}
bool findMinusOneQuadTree(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 0 || arr[i][j] == 1) return 0;
        }
    }
    return 1;
}

bool findZeroQuadTree(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 1 || arr[i][j] == -1) return 0;
        }
    }
    return 1;
}

void solve(int n, int startY, int startX) {
    if (n == 0) return;
    
    if (findOneQuadTree(n, startY, startX)) oneCount++;
    else if (findZeroQuadTree(n, startY, startX)) zeroCount++;
    else if (findMinusOneQuadTree(n, startY, startX)) minusOneCount++;

    else {
        int m1 = n / 3;
        int m2 = n / 3 * 2;
        solve(m1, startY, startX);
        solve(m1, startY, startX + m1);
        solve(m1, startY, startX + m2);
        solve(m1, startY + m1, startX);
        solve(m1, startY + m1, startX + m1);
        solve(m1, startY + m1, startX + m2);
        solve(m1, startY + m2, startX);
        solve(m1, startY + m2, startX + m1);
        solve(m1, startY + m2, startX + m2);
    }
    return;
}

int main() {
    int N; cin >> N;

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    solve(N, 0, 0);
    cout << minusOneCount << endl;
    cout << zeroCount << endl;
    cout << oneCount << endl;
    return 0;
}