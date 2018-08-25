#include<iostream>

using namespace std;

int arr[100001];
int size = 0;

void push(int x){
    cout<<'+'<<endl;
    arr[size++] = x;
}
int pop(){
    cout<<'-'<<endl;
    return  size?arr[--size]:-1;
}
int Size(){ return size; }
bool isEmpty(){ return size?0:1; }
int top(){ return size?arr[size-1]:-1;}
int main(){
    int n; cin>>n;
    
}

