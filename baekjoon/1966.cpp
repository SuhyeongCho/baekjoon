#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findMaxValue(queue< pair<int,int> > q, int N) {
    int result = 0;
    for (int i = 0 ; i < N ; i++) {
        pair<int,int> p = q.front();
        q.pop();
        if (p.second > result) result = p.second;
        q.push(p);
    }
    return result;
}



int main() {
    
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        int N, M; cin >> N >> M;
        
        queue< pair<int,int> > q;
        vector<int> v(N);
        
        for (int i = 0 ; i < N ; i++) {
            int d; cin >> d;
            q.push(make_pair(i,d));
        }
        int count = 1;
        while(count <= N) {
            if (findMaxValue(q, N) == q.front().second) {
                v[q.front().first] = count;
                q.pop();
                count++;
            } else {
                pair<int,int> p = q.front();
                q.pop();
                q.push(p);
            }
        }
        
        cout << v[M] << endl;
    }
    
    
    return 0;
}
