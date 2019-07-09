#include<iostream>

using namespace std;

int N;
int map[2187][2187];
int Minus,Zero,Plus;

bool findMinus(int start1,int end1,int start2,int end2){
    for(int i=start1;i<end1;i++){
        for(int j=start2;j<end2;j++){
            if(map[i][j] != -1) return false;
        }
    }
    return true;
}
bool findPlus(int start1,int end1,int start2,int end2){
    for(int i=start1;i<end1;i++){
        for(int j=start2;j<end2;j++){
            if(map[i][j] != 1) return false;
        }
    }

    return true;
}
bool findZero(int start1,int end1,int start2,int end2){
    for(int i=start1;i<end1;i++){
        for(int j=start2;j<end2;j++){
            if(map[i][j] != 0) return false;
        }
    }

    return true;
}


void find(int a1,int b1,int a2,int b2){
    if(a1 >=b1|| a2>=b2) return;
    if(findMinus(a1,b1,a2,b2)) Minus++;
    else if(findZero(a1,b1,a2,b2)) Zero++;
    else if(findPlus(a1,b1,a2,b2)) Plus++;
    else{
        int c1 = (b1 - a1)/3;
        int c2 = (b2 - a2)/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                find(c1*i+a1,c1*(i+1)+a1,c2*j+a2,c2*(j+1)+a2);
            }
        }
    }
    return;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    find(0,N,0,N);
    cout<<Minus<<endl;
    cout<<Zero<<endl;
    cout<<Plus<<endl;
    return 0;
}