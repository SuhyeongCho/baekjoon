#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[1001][1001];
int main(){
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int len1 = s1.length();
    int len2 = s2.length();
    
    s1 = "0" + s1;
    s2 = "0" + s2;
    
    for (int i = 1 ; i <= len1 ; i++) {
        for (int j = 1 ; j <= len2 ; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

            }
        }
    }
    
    cout << dp[len1][len2] << endl;

    return 0;
}
