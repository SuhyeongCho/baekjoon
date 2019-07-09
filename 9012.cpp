#include<iostream>

using namespace std;

int stack[51];
int size = 0;
void push(int x){
    stack[size++] = x;
}
int pop(){
    return  size?stack[--size]:-1;
}
int Size(){ return size; }
bool isEmpty(){ return size?0:1; }
int top(){ return size?stack[size-1]:-1;}
void clear(){size = 0;}

int PS(){
    clear();
    char arr[51]; cin>>arr;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]=='(') push(1);
        else{
            if(pop()==-1){
                return 0;
            }
        }
    }
    if(isEmpty()) return 1;
    else return 0;
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        if(PS()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}


