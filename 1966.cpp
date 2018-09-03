#include<iostream>
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
void clear(){ front = 0; back = 1;}

int isMax(){
    for(int i=front+2;i<back;i++){
        if(arr[i]>Front()) return 0;
    }
    return 1;
}
int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        clear();
        int count = 0;
        int N,M; cin>>N>>M;
        int arr2[N];
        for(int i=0;i<N;i++){
            cin>>arr2[i];
            push(arr2[i]);
        }
        while(1){
            if(isMax()){
                pop();
                count++;
                if(M==0){
                    cout<<count<<endl;
                    break;
                }
                else{
                    M--;
                    N--;
                }
            }
            else{
                push(pop());
                if(M==0) M = N-1;
                else M--;
            }
        }
    }
}

