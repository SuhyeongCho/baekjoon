#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int L,C;
char arr[15];
bool check(string s){
    char alpha[L+1];
    strcpy(alpha,s.c_str());
    int ja = 0,mo = 0;
    for(int i=0;i<L;i++){
        switch(alpha[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                mo++;
                break;
            default:
                ja++;
        }
    }
    
    if(ja>=2 && mo>=1) return true;
    else return false;
}

//s는 보관중인거, i는 문자열의 인덱스 위치, n은 보관중인거 개수
void fc(string s,int i,int n){
    
    if(i>C){
        return;
    }
    
    if(n>=L){
        if(check(s)) cout<<s<<endl;
        return;
    }
    fc(s+arr[i],i+1,n+1);
    
    fc(s,i+1,n);
    return;
}



int main(){
    
    cin>>L>>C;
    string s;
    
    for(int i=0;i<C;i++){
        cin>>arr[i];
    }
    sort(arr,arr+C);
    
    fc(s,0,0);
    
    return 0;
}
