#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[101];
    cin>>str;
    int count = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == 'c'||str[i] == 's'){
            if(str[i+1] == '=' || str[i+1] == '-'){
                continue;
            }
        }
        else if(str[i]=='n'||str[i]=='l'){
            if(str[i+1]=='j'){
                continue;
            }
        }
        else if(str[i]=='d'&&str[i+1]=='-'){
            continue;
        }
        else if(str[i]=='d'&&str[i+1]=='z'&&str[i+2]=='='){
            i++;
            continue;
        }
        else if(str[i]=='z'&&str[i+1]=='='){
            continue;
        }
        count++;
    }
    cout<<count;
}
