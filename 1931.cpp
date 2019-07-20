#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    
    vector< pair<int,int> > v;
    
    for (int i = 0; i < N ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        
        v.push_back(make_pair(b,a));
    }
    
    sort(v.begin(), v.end());
    
    int count = 0;
    int time = 0;
    
    for (int i = 0 ; i < N ; i++) {
        if (time <= v[i].second) {
            count++;
            time = v[i].first;
        }
    }
    
    cout << count << endl;
    
    return 0;
}

