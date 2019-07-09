#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    int count = 0;
    for(int i=0;i<T;i++){
        char str[101];
        cin>>str;
        int alpha[26]={0};
        bool isOverlap = false;
        for(int j=0;str[j]!='\0';j++){
            int n = str[j] - 'a';
            if(alpha[n] && str[j] != str[j-1]){
                isOverlap = true;
                break;
            }
            alpha[n]++;
        }
        if(!isOverlap) count++;
    }
    cout<<count<<endl;
}
