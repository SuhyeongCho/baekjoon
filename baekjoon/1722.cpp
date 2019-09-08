#include<iostream>
#include<set>
using namespace std;

int N;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N;

    int choice;
    cin>>choice;

    long long *factorial = new long long[N];
    factorial[0] = 1;
    for(int i=1;i<N;i++){
        factorial[i] = i * factorial[i-1];
    }

    set<int> s;
    for(int i=1;i<=N;i++){
        s.insert(i);
    }

    if(choice==1){
        long long int k;
        cin>>k;
        k = k-1;

        for(int i=1;i<N;i++){
            long long int step = k/factorial[N-i];
            set<int>::iterator iter = s.begin();
            for(int j=0;j<step;j++){
                ++iter;
            }
            cout<<*iter<<" ";
            s.erase(iter);
            k -= (step*factorial[N-i]);
        }
        cout<<*s.begin()<<endl;

    }
    else if(choice==2){
        long long int result = 1;
        int data[N];
        for(int i=0;i<N;i++){
            cin>>data[i];
        }
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
    }
    

    return 0;
}



