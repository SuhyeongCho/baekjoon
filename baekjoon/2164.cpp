#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    queue<int> q;
    
    for (int i = 1 ; i <= N ; i++) {
        q.push(i);
    }
    
    
    while(1) {
        if (q.size() == 1) break;

        q.pop();
        
        if (q.size() == 1) break;
        
        int d = q.front();
        q.pop();
        q.push(d);
        
    }
    
    cout << q.front() << endl;
    return 0;
}
