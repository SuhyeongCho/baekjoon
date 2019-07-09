#include<iostream>
#include<cstring>
using namespace std;

int arr[100001];
int front = 0;
int back = 1;

void push(int x){ arr[back++] = x; }
int pop(){ return  front+1!=back?arr[++front]:-1; }
int Size(){ return back-front-1; }
bool isEmpty(){ return Size()?0:1; }
int Front(){return Size()?arr[front+1]:-1;}
int Back(){return Size()?arr[back-1]:-1;}

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
        else if(!strcmp(command,"front")) cout<<Front()<<endl;
        else if(!strcmp(command,"back")) cout<<Back()<<endl;
    }
}
