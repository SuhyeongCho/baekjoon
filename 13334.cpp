#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    int result = 0;
    int d;

    vector< pair<int, int> > v(N);
    for (int i = 0 ; i < N ; i++) {
        int d1, d2;
        scanf("%d %d", &d1, &d2);
        if (d1 < d2) swap(d1, d2);
        v[i].first = d1;
        v[i].second = d2;
    }

    cin >> d;
    sort(v.begin(), v.end());


    priority_queue<int> pq;
    for (int i = 0 ; i < N ; i++) {
        pq.push(-v[i].second);
        while(!pq.empty() && -pq.top() < v[i].first - d) pq.pop();
        result = max(result, (int)pq.size());
    }

    cout << result << endl;
    return 0;
}