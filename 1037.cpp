#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int N; cin >> N;
    vector<int> v(N);
    
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
    
    int result = v[0] * v[v.size() - 1];
    
    cout << result <<endl;
    
    return 0;
}
