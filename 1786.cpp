#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> result;
vector<int> pi;


void getPi(string p) {
    int len = p.length();
    int j = 0;

    for (int i = 1; i < len ; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }

}

void kmp(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();
    int j = 0;

    for (int i = 0 ; i < len1 ; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == len2 - 1) {
                result.push_back(i - len2 + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }

}


int main() {
    string s, p;

    getline(cin, s);
    getline(cin, p);

    pi.resize(p.length());

    getPi(p);
    kmp(s, p);

    int siz = result.size();

    cout << siz << endl;

    for (int i = 0 ; i < siz ; i++) {
        printf("%d\n", result[i] + 1);
    }

    return 0;
}
