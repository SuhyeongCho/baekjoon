#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dp[1001][1001];

int main(){
    
    string s1, s2;
    cin >> s1 >> s2;

    s1 = "0" + s1;
    s2 = "1" + s2;

    int len1 = s1.size();
    int len2 = s2.size();

    for (int i = 0 ; i < len1 ; i++) {
        for (int j = 0 ; j < len2 ; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    vector<int> v;
    int i = len1 - 1;
    int j = len2 - 1;
    while(dp[i][j] != 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else{
            v.push_back(s1[i]);
            i--;
            j--;
        }
    }

    int siz = v.size();
    cout << siz << endl;
    for (int i = 0 ; i < siz ; i++) {
        printf("%c",v.back());
        v.pop_back();
    }
    cout << endl;

    return 0;
}