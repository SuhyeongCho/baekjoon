#include <iostream>

using namespace std;

int main(){
    int a, b, n, w;
    cin >> a >> b >> n >> w;

    int count = 0;

    int resultX, resultY;

    for (int i = 1 ; i <= 1000 ; i++) {
        for (int j = 1 ; j <= 1000 ; j++) {
            if (i + j == n && a * i + b * j == w) {
                count++;
                resultX = i;
                resultY = j;
            }
        }
    }
    if (count != 1) cout << -1 << endl;
    else {
        cout << resultX << " " << resultY << endl;
    }
    return 0;
}
