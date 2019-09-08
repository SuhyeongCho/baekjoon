#include <iostream>
#include <vector>
#include <string>

using namespace std;


int getPi(string s) {
    int len = s.length();
    int j = 0;
    vector<int> pi(len);

    for (int i = 1; i < len ; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        
        if (s[i] == s[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi[len - 1];
}

int main() {
    while(1) {
        string s;
        cin >> s;
        if (s == ".") break;
        int len = s.length();
        int result = getPi(s);
        if (len % (len - result) != 0 && result > len / 2) printf("1\n");
        else printf("%d\n", len / (len - result));
    }
    return 0;
}