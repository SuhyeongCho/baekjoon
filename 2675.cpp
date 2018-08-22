#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        char arr[21];
        cin>>arr;
        for(int j=0;arr[j]!='\0';j++){
            for(int k=0;k<n;k++){
                cout<<arr[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
