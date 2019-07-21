#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N ; cin >> N;
    int pos = 0;
    int check = 1;
    vector<int> v;
    vector<char> result;
    for (int i = 0 ; i < N ; i++) {
        int x; scanf("%d", &x);
        if (!check) continue;
        if (!v.empty() && v.back() == x) {
            v.pop_back();
            result.push_back('-');
        } else {
            if (pos > x) {
                check = 0;
                continue;
            }
            while (pos != x) {
                pos++;
                v.push_back(pos);
                result.push_back('+');

            }
            v.pop_back();
            result.push_back('-');
        }
    }
    
    if (check) {
        int siz = result.size();
        for (int i = 0 ; i < siz ; i++) {
            printf("%c\n", result[i]);
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

