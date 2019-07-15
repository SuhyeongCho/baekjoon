#include <iostream>

using namespace std;

int zero[50];
int one[50];
int main(){
    zero[0] = 1; zero[1] = 0;
    one[0] = 0; one[1] = 1;
    
    for (int i = 2; i <= 40 ; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
    
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        int N; cin >> N;
        cout << zero[N] << " " << one[N] <<endl;
    }
    
    return 0;
}
