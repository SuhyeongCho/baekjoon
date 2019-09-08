#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int,int> > v;

int main() {
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    
    for(int i = 0 ; i < N ; i++) {
        printf("%d %d\n", v[i].second, v[i].first);
    }
    return 0;
}

