#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int map[9][9];
int siz;
struct Point{
    int y;
    int x;
};

vector<struct Point> v;

bool check(int y,int x){
    
    for(int i=0;i<9;i++){
        if(i!=x && map[y][i] == map[y][x])
            return false;
    }
    
    for(int i=0;i<9;i++){
        if(i!=y && map[i][x] == map[y][x])
            return false;
    }
    
    int dy = y/3;
    int dx = x/3;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(map[dy*3+i][dx*3+j] == map[y][x]){
                if(dy*3+i != y && dx*3+j != x){
                    return false;
                }
            }
        }
    }
    
    return true;
}

void printMap(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}


void fc(int i){
    
    if(i>=siz){
        printMap();
        exit(0);
    }
    
    int y = v[i].y;
    int x = v[i].x;
    
    for(int j=1;j<=9;j++){
        map[y][x] = j;
        if(check(y,x))
            fc(i+1);
    }
    map[y][x] = 0;
}

int main(){
    
 
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>map[i][j];
            if(map[i][j] == 0){
                struct Point pos = {i,j};
                v.push_back(pos);
            }
        }
    }
    siz = v.size();
    fc(0);
    
    return 0;
}
