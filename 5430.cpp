#include<iostream>
#include<list>
#include<string>

using namespace std;

list<int> l;
list<string> st;
char arr[2000000];

void arrToDeque(){
    string s="";
    st.clear();
    for(int i=0;arr[i]!='\0';i++){
        char c = arr[i];
        if(c == '[' || c == ']') continue;
        else if(c== ','){
            st.push_back(s);
            s="";
        }
        else s+= c;
    }
    if(s != "") st.push_back(s);
    while(!st.empty()){
        s = st.front();
        st.pop_front();
        int index = atoi(s.c_str());
        l.push_back(index);
    }
}
string dequeToArr(){
    string s = "";
    s += "[";
    while(!l.empty()){
        int num = l.front();
        l.pop_front();
        s += to_string(num);
        if(l.empty()) break;
        else s += ",";
    }
    s += "]";
    return s;
}

int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        char str[1000001]; cin>>str;
        int n; cin>>n;
        cin>>arr;
        l.clear();
        arrToDeque();
        int d_cnt = 0;
        for(int i=0;str[i]!='\n';i++){
            if(str[i] == 'D') d_cnt++;
        }
        if(d_cnt > l.size()){
            cout<<"error"<<endl;
            continue;
        }
        for(int i=0;str[i]!='\n';i++){
            if(str[i] == 'R') l.reverse();
            else if(str[i] == 'D') l.pop_front();
        }
        cout<<dequeToArr()<<endl;
    }
}

