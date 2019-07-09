#include<iostream>
using namespace std;

int main(){
    int a,b,n,w;
    cin>>a>>b>>n>>w;
    int count = 0;
    int X,Y;
    for(int x=1;x<n;x++){
        for(int y=1;y<n;y++){
            if(x+y==n&&a*x + b*y == w){
                count++;
                X = x;
                Y = y;
            }
        }
    }
    if(count == 1){
        cout<<X<<" "<<Y<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
