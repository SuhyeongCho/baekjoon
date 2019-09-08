#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   
    string s; cin >> s;
    
    vector<int> v;
    int len = s.length();
    int num = 0;
    int plus = 0;
    for (int i = 0 ; i < len ; i++) {
        switch (s[i]) {
            case '+':
                plus += num;
                num = 0;
                break;
            case '-':
                plus += num;
                v.push_back(plus);
                num = 0;
                plus = 0;
                break;
            default:
                num = num * 10 + (s[i] - '0');
                break;
        }
    }
    plus += num;
    v.push_back(plus);
    
    int siz = v.size();
    for (int i = 1 ; i < siz ; i++) {
        v[0] -= v[i];
    }
    
    cout << v[0] <<endl;
    return 0;
}




