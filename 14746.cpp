#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    int c1, c2;
    cin >> c1 >> c2;

    vector< pair<int, int> > v;

    for (int i = 0 ; i < N ; i++) {
        int d; scanf("%d", &d);
        v.push_back(make_pair(d, 0));
    }

    for (int i = 0 ; i < M ; i++) {
        int d; scanf("%d", &d);
        v.push_back(make_pair(d, 1));
    }

    sort(v.begin(), v.end());

    int result = 1987654321;
    int rCount = 0;

    for (int i = 0 ; i < N + M - 1; i++) {
        if (v[i].second == v[i + 1].second) continue;
        int diff = v[i + 1].first - v[i].first;
        if (diff < result) {
            result = diff;
            rCount = 0;
        }
        if (diff == result) {
            rCount++;
        }
    }

    cout << result + abs(c1 - c2) << " " << rCount << endl;

    return 0;
}