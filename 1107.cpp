#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void makeStack(vector<int>& v,int num){
    if(num==0)v.push_back(0);
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


int queueToInt(queue<int> q){
    int num=0;
    while(!q.empty()){
        num *= 10;
        num += q.front();
        q.pop();
    }
    return num;
}

int main(){
    vector<int> v;
    queue<int> q;
    
    int N; cin>>N;
    int n; cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++) cin>>arr[i];
    makeStack(v,N);
    int count = 0;
    
    while(!v.empty()){
        int num = v.back();
        v.pop_back();
        if(check(arr,n,num)){
            q.push(num);
        }
        else{
            int next=10,prev=-1;
            for(int i=num+1;i<=9;i++){
                if(check(arr,n,i)){
                    next = i;
                    break;
                }
            }
            for(int i=num-1;i>=0;i--){
                if(check(arr,n,i)){
                    prev = i;
                    break;
                }
            }
            cout<<"next,prev : "<<next<<" "<<prev<<endl;
            if(next-num>num-prev||next==10){
                int fin = -1;
                q.push(prev);
                for(int i=9;i>=0;i--){
                    if(check(arr,n,i)){
                        fin = i;
                        break;
                    }
                }
                for(int i=0;i<v.size();i++){
                    q.push(fin);
                }
            }
            else if(next-num<num-prev||prev == -1){
                int fin = 10;
                q.push(next);
                for(int i=0;i<=9;i++){
                    if(check(arr,n,i)){
                        fin = i;
                        break;
                    }
                }
                for(int i=0;i<v.size();i++){
                    q.push(fin);
                }
            }
            else{
                queue<int> q1,q2;
                int fin1,fin2;
                for(int i=9;i>=0;i--){
                    if(check(arr,n,i)){
                        fin1 = i;
                        break;
                    }
                }
                for(int i=0;i<=9;i++){
                    if(check(arr,n,i)){
                        fin2 = i;
                        break;
                    }
                }
                q1=q; q2=q;
                q1.push(prev); q2.push(next);
                for(int i=0;i<v.size();i++){q1.push(fin1);q2.push(fin2);}
                cout<<"q1 : "<<queueToInt(q1)<<endl;
                cout<<"q2 : "<<queueToInt(q2)<<endl;
                
                if(num-queueToInt(q1)>queueToInt(q2)-num) q = q2;
                else q = q1;
            }
            break;
        }
    }
    
    for(int i=0;i<q.size();i++)count++;
    
    
    int result = queueToInt(q);
    cout<<"result : "<<result<<endl;
    int diff;
    if(result>N) diff = result-N;
    else diff = N - result;
    cout<<"diff : "<<diff<<endl;
    for(int i=0;i<diff;i++) count++;
    int newdiff = N>100?N-100:100-N;
    if(count>newdiff) count = newdiff;
    cout<<count<<endl;
}
