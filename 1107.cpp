#include<iostream>
#include<vector>

using namespace std;
void makeStack(vector<int>& v,int num){
    while(num){
        int mod = num%10;
        v.push_back(mod);
        num /= 10;
    }
}
//리모컨 버튼이 멀쩡하면 1 반환
bool check(int *arr,int n,int num){
    for(int i=0;i<n;i++){
        if(arr[i]==num) return 0;
    }
    return 1;
}
int main(){
    vector<int> v;
    int N; cin>>N;
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    makeStack(v1,N);
    int count = 0;
    while(!v.empty()){
        int num = v.back();
        if(check(num)){
            count++;
        }
        else{
            
        }
    }
}
