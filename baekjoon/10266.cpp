#include <iostream>
#include <vector>

using namespace std;

vector<int> watch(720000, 0);
vector<int> pi(360000,0);

vector<int> p(360000,0);

void getPi(vector<int> p) {
    int siz = p.size();
    int j = 0;
    for (int i = 1 ; i < siz ; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
}

bool kmp(vector<int> s, vector<int> p) {
    int siz1 = s.size();
    int siz2 = p.size();
    int j = 0;
    for (int i = 0 ; i < siz1 ; i++ ) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == siz2 - 1) {
                return true;
            } else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int d;
        scanf("%d", &d);
        watch[d] = 1;
        watch[d + 360000] = 1;
    }

    for (int i = 0 ; i < N ; i++) {
        int d;
        scanf("%d", &d);
        p[d] = 1;
    }

    getPi(p);


    bool result = kmp(watch, p);

    if (result) printf("possible\n");
    else printf("impossible\n");

    return 0;
}