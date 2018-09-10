#include<iostream>
#include<cstring>
int arr[3000000];
int size = 0;
using namespace std;

void add(int);
void remove(int);
int check(int);
void toggle(int);
void all();
void empty();

int main(){
    int M; cin>>M;
    for(int i=0;i<M;i++){
        
    }
}

void add(int x){
    if(check(x)) return;
    arr[size++] = x;
}

void remove(int x){
//
}
