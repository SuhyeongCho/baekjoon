#include <iostream>
#include <string>

using namespace std;

int N;
string str;
long long int dp[201][201];
bool check(char a,char b){
    if(a == '(' && b == ')') return 1;
    else if(a == '{' && b == '}') return 1;
    else if(a == '[' && b == ']') return 1;
    else return 0;
}

int main(){
    cin>>N;
    cin>>str;

    

    return 0;
}