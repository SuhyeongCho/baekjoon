#include<iostream>
#include<vector>
using namespace std;

int map[9][9];
vector< pair<int, int> > v;
int siz;

void printMap() {
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

bool check(int y, int x) {
    for (int i = 0 ; i < 9 ; i++) {
        if (i != y && map[y][x] == map[i][x]) return false;
        if (i != x && map[y][x] == map[y][i]) return false;
    }
    int y1 = y / 3;
    int x1 = x / 3;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(map[y1*3+i][x1*3+j] == map[y][x]){
                if(y1*3+i != y && x1*3+j != x){
                    return false;
                }
            }
        }
    }
    return true;
}

void fc(int pos) {
    if (pos >= siz) {
        printMap();
        exit(0);
    }
    int y = v[pos].first;
    int x = v[pos].second;

    for (int i = 1 ; i <= 9 ; i++) {
        map[y][x] = i;
        if (check(y,x)) {
            fc(pos + 1);
        }
        map[y][x] = 0;
    }
}

int main(){

    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    siz = v.size();    
    fc(0);
 
    return 0;
}
