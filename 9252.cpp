#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[1001][1001];
int sol[1001][1001];
int main(){
    string s1,s2;
    cin>>s1>>s2;
    s1 = '1'+s1;
    s2 = '2'+s2;
    for(int i=1;i<s1.length();i++){
        for(int j=1;j<s2.length();j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                sol[i][j] = 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j] == dp[i-1][j]) sol[i][j] = 2;
                else sol[i][j] = 3;
            }
        }
    }

    int a = s1.length();
    int b = s2.length();
    string s = "";
    a--;b--;
    while(sol[a][b]){
        if(sol[a][b] == 1){
            s = s1[a] + s;
            a--;
            b--;
        }
        else if(sol[a][b] == 2){
            a--;
        }
        else if(sol[a][b] ==3){
            b--;
        }
    }
    cout<<dp[s1.length()-1][s2.length()-1]<<endl;
    cout<<s<<endl;
    return 0;
}