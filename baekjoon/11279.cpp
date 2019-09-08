#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N; cin >> N;
    priority_queue<int, vector<int>, less<int> > pq;
    
    for (int i = 0 ; i < N ; i++) {
        int d; scanf("%d",&d);
        if (d == 0) {
            if (pq.empty()) printf("0\n");
            else {
                printf("%d\n",pq.top());
                pq.pop();
            }
        } else {
            pq.push(d);
        }
    }
    return 0;
}
