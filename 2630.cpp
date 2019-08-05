#include <iostream>

using namespace std;

int arr[128][128];
int countBlue = 0;
int countWhite = 0;

int findBlueColor(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 0) return 0;
        }
    }
    return 1;
}

int findWhiteColor(int n, int startY, int startX) {
    for (int i = startY ; i < startY + n ; i++) {
        for (int j = startX ; j < startX + n ; j++) {
            if (arr[i][j] == 1) return 0;
        }
    }
    return 1;
}

void solve(int n, int startY, int startX) {
    if (n == 0) return;
    if (findBlueColor(n, startY, startX)) countBlue++;
    else if (findWhiteColor(n, startY, startX)) countWhite++;
    else {
        int m = n / 2;
        solve(m, startY, startX);
        solve(m, startY + m, startX);
        solve(m, startY, startX + m);
        solve(m, startY + m, startX + m);
    }
}

int main () {
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    solve(N, 0, 0);
    
    cout << countWhite << endl << countBlue << endl;
    return 0;
}