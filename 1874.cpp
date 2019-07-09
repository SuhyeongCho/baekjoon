#include<iostream>

using namespace std;

int arr[100001];
char arr3[200002];
int size = 0;
int charpos = 0;
void push(int x){
    arr3[charpos++] = '+';
    arr[size++] = x;
}
int pop(){
    arr3[charpos++] = '-';
    return  size?arr[--size]:-1;
}
int Size(){ return size; }
bool isEmpty(){ return size?0:1; }
int top(){ return size?arr[size-1]:-1;}
int main(){
    int n; cin>>n;
    int arr2[n];
    for(int i=0;i<n;i++) cin>>arr2[i];
    int pos = 1;
    for(int i=0;i<n;i++){
        while(1){
            if(top()==arr2[i]){
                pop();
                break;
            }
            else if(top()>arr2[i]){
                cout<<"NO"<<endl;
                return 0;
            }
            else{
                push(pos++);
            }
        }
    }
    for(int i=0;i<2*n;i++) cout<<arr3[i]<<'\n';
}

