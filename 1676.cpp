#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    
    int result = 0;
    result += N / 5;
    result += N / 25;
    result += N / 125;
    
    cout << result << endl;
    return 0;
}
