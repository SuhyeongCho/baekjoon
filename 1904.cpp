#include <iostream>

using namespace std;

long long int fi[1000001];
int main() {
    int N; cin >> N;
    
    fi[1] = 1;
    fi[2] = 2;
    
    for (int i = 3; i <= N ; i++) {
        fi[i] = (fi[i - 1] + fi[i - 2]) % 15746;
    }
    
    cout << fi[N] << endl;
    return 0;
}

