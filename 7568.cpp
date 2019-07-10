#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin>>N;
    vector< pair<int,int> > v;
    
    for (int i = 0 ; i < N ; i++) {
        int weight, height;
        cin >> weight >> height;
        v.push_back(make_pair(weight,height));
    }
    for(int i = 0 ; i < N ; i++) {
        int count = 0;
        for (int j = 0 ; j < N ; j ++) {
            if (i == j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second) count++;
        }
        cout << count + 1 << " ";
    }
    cout << endl;
    return 0;
}
