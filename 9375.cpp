#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        int N; cin >> N;
        vector< pair<string,int> > v;
        for (int i = 0 ; i < N ; i++) {
            string s1, s2; cin >> s1 >> s2;
            int siz = v.size();
            int check = 0;
            for (int j = 0 ; j < siz ; j++) {
                if (v[j].first == s2) {
                    v[j].second++;
                    check = 1;
                }
            }
            if (!check) {
                v.push_back(make_pair(s2,1));
            }
        }
        
        int siz = v.size();
        int result = 1;
        for (int i = 0 ; i < siz ; i++) {
            result *= (v[i].second + 1);
        }
        
        cout << result - 1 << endl;
    }
    
    return 0;
}
