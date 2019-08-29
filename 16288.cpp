#include <iostream>
#include <vector>

using namespace std;


int main(){
    int N, K; cin >> N >> K;
    vector<int> v(N);
    vector<int> s[K];
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &v[i]);
    }

    for (int i = 0 ; i < K ; i++) {
        s[i].push_back(-1);
    }

    bool result = false;
    for (int i = 0 ; i < N ; i++) {
        result = false;
        for (int j = 0 ; j < K ; j++) {
            if (s[j].back() < v[i]) {
                s[j].push_back(v[i]);
                result = true;
                break;
            }
        }

        if (result == false) break;
    }

    if (result) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
