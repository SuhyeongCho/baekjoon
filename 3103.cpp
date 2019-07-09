#include<iostream>
#include<set>
using namespace std;

int N;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N;
    
    int k;
    cin>>k;
    
    long long *factorial = new long long[N];
    factorial[0] = 1;
    for(int i=1;i<N;i++){
        factorial[i] = i * factorial[i-1];
    }
    
    int data[N];
    for(int i=0;i<N;i++){
        cin>>data[i];
    }
    for(int j=0;j<k;j++){
        set<int> s;
        for(int i=1;i<=N;i++){
            s.insert(i);
        }
        long long int result = 1;
        int a,b;
        cin>>a>>b;
        swap(data[a-1],data[b-1]);
        for(int i=0;i<N;i++){
            int count=0;
            for(set<int>::iterator iter = s.begin();iter!=s.end();++iter){
                if(*iter == data[i]){
                    s.erase(iter);
                    result += (count * factorial[N-i-1]);
                    break;
                }
                count++;
            }
            
        }
        cout<<result<<endl;
        swap(data[a-1],data[b-1]);
    }
    
    return 0;
}




