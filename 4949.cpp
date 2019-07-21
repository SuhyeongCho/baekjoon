#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    vector<char> v;
    
    while(1) {
        string s;
        char tmp[101];
        cin.getline(tmp,101);
        s = tmp;
        if (s == ".") break;
        int len = s.length();
        int result = 1;
        for (int i = 0 ; i < len ; i++) {
            if (s[i] == '(') {
                v.push_back('(');
            } else if (s[i] == '[') {
                v.push_back('[');
            } else if (s[i] == ')') {
                if (v.empty()) {
                    result = 0;
                    break;
                } else {
                    if (v.back() == '(') {
                        v.pop_back();
                    } else {
                        result = 0;
                        break;
                    }
                }
            } else if (s[i] == ']') {
                if (v.empty()) {
                    result = 0;
                    break;
                } else {
                    if (v.back() == '[') {
                        v.pop_back();
                    } else {
                        result = 0;
                        break;
                    }
                }
            }
        }
        
        if (v.size()) result = 0;
        if (result) cout << "yes" << endl;
        else cout << "no" << endl;

        v.clear();
    }
    return 0;
}
