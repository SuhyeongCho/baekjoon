#include<iostream>
#include<list>
#include<string>

using namespace std;

list<int> l;
list<string> st;
char arr[200005];

void arrToDeque(int n){
    string s="";
    for(int i=0;arr[i]!='\0';i++){
        char c = arr[i];
        if(c == '[' || c == ']') continue;
        else if(c== ','){
            st.push_back(s);
            s="";
        }
        else s+= c;
    }
    for(int i=0;i<n;i++){
        s = st.front();
        st.pop_front();
        int index = atoi(s.c_str());
        l.push_back(index);
    }
}
void dequeToArr(){
    
}

int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        char str[100000]; cin>>str;
        int n; cin>>n;
        cin>>arr;
        l.clear();
        arrToDeque(n);
        int d_cnt = 0;
        for(int i=0;str[i]!='\n';i++){
            if(str[i] == 'D') d_cnt++;
        }
        if(d_cnt > l.size()){
            cout<<"error"<<endl;
            break;
        }
        for(int i=0;str[i]!='\n';i++){
            if(str[i] == 'R') l.reverse();
            else if(str[i] == 'D') l.pop_front();
        }
        dequeToArr();
        cout<<arr<<endl;
    }
}

