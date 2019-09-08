#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool isVisited[9];

void fc(int n) {
    if (n > M) {
        for (int i = 1 ; i <= M ; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = arr[n - 1] + 1 ; i <= N ; i++) {
        if (isVisited[i] == false) {
            isVisited[i] = true;
            arr[n] = i;
            fc(n+1);
            isVisited[i] = false;
        }
    }
    
}
int main() {
    cin >> N >> M;

    fc(1);

    return 0;
}