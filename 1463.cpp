#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N; cin >> N;
    
    queue<int> q;
    q.push(N);
    
    int result = 0;
    while(!q.empty()) {
        int siz = q.size();
        for (int i = 0; i < siz ; i++) {
            int d = q.front();
            q.pop();
            
            if (d == 1) {
                cout << result << endl;
                return 0;
            }
            
            if (d % 3 == 0) q.push(d / 3);
            if (d % 2 == 0) q.push(d / 2);
            q.push(d - 1);
        }
        
        result++;
    }
    
    
    return 0;
}
