#include <iostream>
#include <string>

using namespace std;

int main() {
    int N; cin>>N;
    
    int num = 0;
    int i = 0;
    while (i < N) {
        num++;
        string s = to_string(num);
        if (s.find("666") != -1) i++;
    }
    cout << num <<endl;
    return 0;
}

