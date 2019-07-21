#include <iostream>
#include <vector>
using namespace std;


int main(){
    
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        string s; cin >> s;
        vector<int> v;
        int len = s.length();
        int result = 1;
        for (int i = 0 ; i < len ; i++) {
            if (s[i] == '(') {
                v.push_back(0);
            } else {
                if (v.empty()) {
                    result = 0;
                    break;
                }
                else v.pop_back();
            }
        }
        if (v.size()) result = 0;
        
        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


