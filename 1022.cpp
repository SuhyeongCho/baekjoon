#include <iostream>

using namespace std;

int main(){
    int r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    int map[r2-r1+1][c2-c1+1];

    int y=0,x=0;
    int check = 1;
    int number = 0;
    int max = 0;
    while(!((y>5000 && x>5000)||(y>5000 && x<-5000)||(y<-5000 && x>5000)||(y<-5000 && x<-5000))){
        for(int i=1;i<=check;i++){
            number++;
            if(x>=c1 && x<=c2 && y>=r1 && y<=r2){
                map[y-r1][x-c1] = number;
                max = number;
            }
            x++;
        }
        for(int i=1;i<=check;i++){
            number++;
            if(x>=c1 && x<=c2 && y>=r1 && y<=r2){
                map[y-r1][x-c1] = number;
                max = number;

            }
            y--;
        }
        check++;
        for(int i=1;i<=check;i++){
            number++;
            if(x>=c1 && x<=c2 && y>=r1 && y<=r2){
                map[y-r1][x-c1] = number;
                max = number;
            }
            x--;
        }
        for(int i=1;i<=check;i++){
            number++;
            if(x>=c1 && x<=c2 && y>=r1 && y<=r2){
                map[y-r1][x-c1] = number;
                max = number;

            }
            y++;
        }
        check++;
    }

    int cnt = 0;
    while(max){
        max/=10;
        cnt++;
    }
    for(int i=0;i<r2-r1+1;i++){
        for(int j=0;j<c2-c1+1;j++){
            printf("%*d ",cnt,map[i][j]);
        }
        cout<<endl;
    }
    return 0;
}