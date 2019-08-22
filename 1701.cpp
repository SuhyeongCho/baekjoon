#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxValue;

void getPi(string s) {
    int len = s.length();
    vector<int> pi(len);
    int j = 0;
    for (int i = 1 ; i < len ; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
            pi[i] = j;
            if (maxValue < pi[i]) maxValue = pi[i];
        }
    }
}

int main() {
    string s;
    cin >> s;

    int len = s.length();
    for (int i = 0 ; i < len ; i++) {
        getPi(&s[i]);
    }

    cout << maxValue << endl;
    return 0;
}