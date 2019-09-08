#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v;
    
    for (int i = 0 ; i < N ; i++) {
        int x; cin >> x;
        if (x) {
            v.push_back(x);
        } else {
            v.pop_back();
        }
    }
    
    int result = 0;
    int siz = v.size();
    for (int i = 0 ; i < siz ; i++) {
        result += v[i];
    }
    
    cout << result << endl;
    return 0;
}
