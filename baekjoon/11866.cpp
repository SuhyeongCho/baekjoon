#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    queue<int> q;
    vector<int> v;
    
    for (int i = 1 ; i <= N ; i++) {
        q.push(i);
    }
    
    int d = 0;
    while (!q.empty()) {
        for (int i = 0 ; i < M - 1 ; i++) {
            d = q.front(); q.pop(); q.push(d);
        }
        d = q.front(); q.pop(); v.push_back(d);
    }
    
    cout << "<";
    for (int i = 0 ; i < N - 1 ; i++) {
        cout << v[i] << ", ";
    }
    cout << v[N - 1] << ">" << endl;
    return 0;
}


