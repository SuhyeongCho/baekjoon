#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;
int result = 0;

int maxfc(int n, int m) {
    int maxValue = 0;
    for (int i = n ; i < m ; i++) {
        maxValue = max(maxValue, v[i]);
    }

    return maxValue;
}

void solve(int n, int m) {

    if (n + 1 == m) return;
    
    int d1 = maxfc(n, (n + m) / 2);
    int d2 = maxfc((n + m) / 2, m);
    int diff = abs(d1 - d2);
    result += diff;

    solve(n, (n + m) / 2);
    solve((n + m) / 2, m);
}

int main() {
    int N; cin >> N;
    v.resize( ( 1 << (N + 1) ) - 1 );
    v[0] = 0;
    v[1] = 0;

    for (int i = 2 ; i < ( 1 << (N + 1) ) ; i++) {
        int d; scanf("%d", &d);
        v[i] = v[i / 2] + d;
        result += d;
    }

    int start = 1 << N;
    int end = 1 << (N + 1);

    solve(start, end);

    cout << result << endl;

    return 0;

}