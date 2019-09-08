#include <stdio.h>
#include <queue>

using namespace std;

struct Map {
    int value;
    int y;
    int x;
};

struct compare {
    bool operator()(struct Map &a, struct Map &b) {
        return a.value < b.value;
    }
};

int arr[1500][1500];
int main() {
    int N; scanf("%d", &N);
    priority_queue<struct Map, vector<struct Map>, compare> pq;

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0 ; i < N ; i++) {
        struct Map map = {arr[N - 1][i], N - 1, i};
        pq.push(map);
    }

    struct Map result;
    for (int i = 0 ; i < N ; i++) {
        result = pq.top();
        pq.pop();

        struct Map add = {arr[result.y - 1][result.x], result.y - 1, result.x};
        pq.push(add);
    }

    printf("%d\n", result.value);
    
    return 0;
}




