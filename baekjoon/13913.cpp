#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int isVisited[100001];


int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0 ; i <= 100000 ; i++) {
        isVisited[i] = -1;
    }

    queue<int> q;
    q.push(N);
    int level = 0;

    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0 ; i < siz ; i++) {
            int d = q.front();
            q.pop();

            if (d == K) {
                cout << level << endl;
                vector<int> v;
                v.push_back(d);
                while (d != N) {
                    d = isVisited[d];
                    v.push_back(d);
                }

                for (int i = 0 ; i < level + 1 ; i++) {
                    printf("%d ", v.back());
                    v.pop_back();
                }
                cout << endl;
                return 0;
            }

            if (d - 1 >= 0 && isVisited[d - 1] == -1) {
                isVisited[d - 1] = d;
                q.push(d - 1);
            }

            if (d + 1 <= 100000 && isVisited[d + 1] == -1) {
                isVisited[d + 1] = d;
                q.push(d + 1);
            }
            
            if (d * 2 <= 100000 && isVisited[d * 2] == -1) {
                isVisited[d * 2] = d;
                q.push(d * 2);
            }

        }
        level++;
    }

    return 0;
}