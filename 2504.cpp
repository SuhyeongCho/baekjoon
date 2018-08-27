#include<iostream>

using namespace std;

int arr[31];

int size = 0;
void push(int x){
    arr[size++] = x;
}
int pop(){
    return  size?arr[--size]:-1;
}
int Size(){ return size; }
bool isEmpty(){ return size?0:1; }
int top(){ return size?arr[size-1]:-1;}

int main(){
    char str[31]; cin>>str;
    int cnt[31]={0};
    int sz=0;
    for(int i=0;str[i]!='\n';i++){
        if(str[i]=='('||str[i]=='['){
        }
        else if(str[i]==')'){
        }
        else if(str[i]==']'){
        }
    }
}
