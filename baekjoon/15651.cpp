#include <iostream>

using namespace std;

int N, M;
int arr[9];

void fc(int n) {
    if (n > M) {
        for (int i = 1 ; i <= M ; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1 ; i <= N ; i++) {
        arr[n] = i;
        fc(n+1);
    }
    
}
int main() {
    cin >> N >> M;

    fc(1);

    return 0;
}