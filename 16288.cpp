#include<iostream>

using namespace std;


int main(){
    int N,K; cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    
//    int pos = 1;
//    for(int i=0;i<N-K+1;i++){
//        bool check = false;
//        for(int j=i;j<i+K;j++){
//            if(arr[j] == pos){
//                swap(arr[j],arr[i]);
//                check = true;
//                pos++;
//                break;
//            }
//        }
//        if(check == false){
//            cout<<"NO"<<endl;
//            return 0;
//        }
//    }
//    cout<<"YES"<<endl;
    return 0;
}
