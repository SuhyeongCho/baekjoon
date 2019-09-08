#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
    bool operator()(int &a,int &b) {
        if (abs(a) == abs(b)) {
            if (a < 0) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return abs(a) > abs(b);
        }
    }
};


int main() {
    int N; cin >> N;
    priority_queue<int, vector<int>, compare > pq;
    
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


