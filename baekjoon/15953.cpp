#include <iostream>

using namespace std;

int main () {
    int T; cin >> T;
    for (int ttt = 0 ; ttt < T ; ttt++) {
        int a, b;
        cin >> a >> b;
        int result = 0;
        if (a == 0) result += 0;
        else if (a <= 1) result += 500;
        else if (a <= 3) result += 300;
        else if (a <= 6) result += 200;
        else if (a <= 10) result += 50;
        else if (a <= 15) result += 30;
        else if (a <= 21) result += 10;
        else result += 0;

        if (b == 0) result += 0;
        else if (b <= 1) result += 512;
        else if (b <= 3) result += 256;
        else if (b <= 7) result += 128;
        else if (b <= 15) result += 64;
        else if (b <= 31) result += 32;
        else result += 0;

        cout << result * 10000 << endl;
    }
    return 0;
}