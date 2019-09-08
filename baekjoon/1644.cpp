#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int N;

bool isPrime(int n){
    if(n ==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}




int main(){
    
    cin>>N;
    
    for(int i=1;i<=N;i++){
        if(isPrime(i)) v.push_back(i);
    }
    
  
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum = 0;
        for(int j=i;j<v.size();j++){
            sum = sum + v[j];
            if(sum == N){
                cnt++;
                break;
            }
            else if(sum > N) break;
        }
    }
    
    cout<<cnt<<endl;
    
    return 0;
}
