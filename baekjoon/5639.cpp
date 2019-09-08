#include <iostream>

using namespace std;

int arr[1000001];

void fc(int s, int e) {

    if (s > e) return;

    int root = arr[s];

    int index = s + 1;
    int cnt = 0;
    while (root >= arr[index++]) cnt++;
    fc(s + 1, s + cnt);
    fc(s + cnt + 1, e);
    printf("%d\n", root);
}

int main() {
    int N = 0;
    while(scanf("%d", &arr[N++]) != -1);
    arr[N - 1] = 987654321;

    fc(0,N - 2);
    return 0;
}