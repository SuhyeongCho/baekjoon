#include<iostream>
#include<cstring>
using namespace std;

int arr[10001];
int size = 0;

void push(int x){ arr[size++] = x; }
int pop(){ return  size?arr[--size]:-1; }
int Size(){ return size; }
bool isEmpty(){ return size?0:1; }
int top(){ return size?arr[size-1]:-1;}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char command[6];
        cin>>command;
        if(!strcmp(command,"push")){
            int x; cin>>x;
            push(x);
        }
        else if(!strcmp(command,"pop")) cout<<pop()<<endl;
        else if(!strcmp(command,"size")) cout<<Size()<<endl;
        else if(!strcmp(command,"empty")) cout<<isEmpty()<<endl;
        else if(!strcmp(command,"top")) cout<<top()<<endl;
    }
}
