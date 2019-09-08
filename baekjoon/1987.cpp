#include<iostream>

using namespace std;

int R,C;
char **data;
bool **isvisited;

bool *check;

bool promise(int r,int c){
    int alpha = data[r][c];
    if(isvisited[r][c]) return false;
    if(alpha == 0) return false;
    if(check[alpha-'A'] == true) return false;
    return true;
}
int alphabet(int r,int c){
    if(promise(r,c)){
        int ch = data[r][c]-'A';
        check[ch] = true;
        isvisited[r][c] = true;
        
        int a1 = alphabet(r-1,c);
        int b1 = alphabet(r+1,c);
        int c1 = alphabet(r,c-1);
        int d1 = alphabet(r,c+1);
        
        check[ch] = false;
        isvisited[r][c] = false;
        
        int e1 = max(max(a1,b1),max(c1,d1))+1;
        return e1;
    }
    else return 0;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int R,C;
    cin>>R>>C;
    data = new char*[R+2];
    isvisited = new bool*[R+2];
    for(int i=0;i<R+2;i++){
        data[i] = new char[C+2];
        isvisited[i] = new bool[C+2];
    }
    for(int i=0;i<R+2;i++){
        for(int j=0;j<C+2;j++){
            data[i][j] = 0;
            isvisited[i][j] = 0;
        }
    }
    check = new bool[26];
    for(int i=0;i<26;i++){
        check[i] = 0;
    }
    
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>data[i][j];
        }
    }
    
    
    cout<<alphabet(1,1)<<endl;
    
    return 0;
}






