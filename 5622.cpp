#include<iostream>
#include<cstring>
using namespace std;

void changeToInt(char * str){
    for(int i=0;str[i]!='\0';i++){
        switch(str[i]){
                case 'A': case 'B': case 'C': str[i] = 2;break;
                case 'D': case 'E': case 'F': str[i] = 3;break;
                case 'G': case 'H': case 'I': str[i] = 4;break;
                case 'J': case 'K': case 'L': str[i] = 5;break;
                case 'M': case 'N': case 'O': str[i] = 6;break;
            case 'P': case 'Q': case 'R': case 'S': str[i] = 7;break;
                case 'T': case 'U': case 'V': str[i] = 8;break;
            case 'W': case 'X': case 'Y': case 'Z': str[i] = 9;break;
        }
    }
}
int main(){
    char dial[16];
    cin>>dial;
    int n = strlen(dial);
    changeToInt(dial);
    int sum = 0;
    for(int i=0;dial[i]!='\0';i++){
        sum += dial[i];
    }
    cout<<sum+n;
    
}
