#include<iostream>
using namespace std;

int arr[2999999];
int front = 0;
int back = 1;

void push(int x){ arr[back++] = x; }
int pop(){ return  front+1!=back?arr[++front]:-1; }
int Size(){ return back-front-1; }
bool isEmpty(){ return Size()?0:1; }
int Front(){return Size()?arr[front+1]:-1;}
int Back(){return Size()?arr[back-1]:-1;}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)push(i);
    int cnt = 1;
    cout<<"<";
    while(!isEmpty()){
        if(cnt%M == 0){
            cout<<pop();
            if(isEmpty()) cout<<">";
            else cout<<", ";
        }
        else{
            push(pop());
        }
        cnt++;
    }
    cout<<endl;
    
}



