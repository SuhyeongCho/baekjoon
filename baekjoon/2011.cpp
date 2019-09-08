#include<iostream>
#include<cstring>

using namespace std;

char str[5001];
int dp[5001];
int main(){
    cin>>str;
    int len = strlen(str);

    for(int i=0;i<len;i++){
        if(str[i] < '0' || str[i] > '9'){
            cout<<0<<endl;
            return 0;
        }
    }
    
    if(str[0] == '0'){
        cout<<0<<endl;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=len;i++){
        if(str[i-1] != '0')
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1]<= '6'))
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
    }
    cout<<dp[len]<<endl;
    return 0;
}
