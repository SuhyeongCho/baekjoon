#include<iostream>

using namespace std;
int main(){
    char str[1000001];
    cin>>str;
    int alpha[26]={0};
    for(int i=0;str[i]!='\0';i++){
        int n;
        if(str[i]>='a') n = str[i]-'a';
        else n = str[i] -'A';
        alpha[n]++;
    }
    int max = 0;
    for(int i=1;i<26;i++){
        if(alpha[i]>alpha[max]) max = i;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==alpha[max]&&i!=max){
            max = -1;
        }
    }
    if(max==-1) cout<<'?';
    else cout<<(char)(max+'A');
}
