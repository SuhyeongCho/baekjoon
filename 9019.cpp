#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;



int main() {
    int T; cin >> T;
    for (int ttt = 0 ; ttt < T ; ttt++) {

        int A, B;
        cin >> A >> B;

        queue<int> q;
        q.push(A);

        vector<pair<char,int> > v(10000);

        int level = 0;

        bool flag = false;

        while(!q.empty()) {
            int siz = q.size();
            for (int i = 0 ; i < siz ; i++) {
                int d = q.front();
                q.pop();

                if (d == B) {
                    vector<int> result;
                    result.push_back(v[d].first);
                    while(v[d].second != A) {
                        d = v[d].second;
                        result.push_back(v[d].first);
                    }

                    int siz = result.size();
                    for (int i = 0 ; i < siz ; i++) {
                        printf("%c",result.back());
                        result.pop_back();
                    }
                    cout << endl;
                    
                    flag = true;
                    break;
                }
                if (v[(d * 2) % 10000].first == 0) {
                    q.push((d * 2) % 10000);
                    v[(d * 2) % 10000].first = 'D';
                    v[(d * 2) % 10000].second = d;
                }

                if (v[(d + 9999) % 10000].first == 0) {
                    q.push((d + 9999) % 10000);
                    v[(d + 9999) % 10000].first = 'S';
                    v[(d + 9999) % 10000].second = d;
                }

                if (v[(d % 1000) * 10 + (d / 1000)].first == 0) {
                    q.push((d % 1000) * 10 + (d / 1000));
                    v[(d % 1000) * 10 + (d / 1000)].first = 'L';
                    v[(d % 1000) * 10 + (d / 1000)].second = d;
                }

                if (v[(d / 10) + (d % 10) * 1000].first == 0) {
                    q.push((d / 10) + (d % 10) * 1000);
                    v[(d / 10) + (d % 10) * 1000].first = 'R';
                    v[(d / 10) + (d % 10) * 1000].second = d;
                }

            }
            level++;
            if (flag) break;
        }
    }
    return 0;
}


