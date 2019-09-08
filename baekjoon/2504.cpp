#include<iostream>
#include<vector>
using namespace std;

int main(){
    char str[31]; cin>>str;
    vector<int> v;
    int sum = 0;
    for(int i=0;str[i]!='\0';i++){
        char c = str[i];
        if(c == '(') v.push_back(-2);
        else if(c == '[') v.push_back(-3);
        else{
            if(v.empty()){
                cout<<0<<endl;
                return 0;
            }
            int pop = v.back(); v.pop_back();
            sum = 0;
            while(pop>0){
                sum += pop;
                if(v.empty()){
                    cout<<0<<endl;
                    return 0;
                }
                pop = v.back(); v.pop_back();
            }
            if(sum == 0) sum = 1;
            if(c == ')'){
                if(pop == -3){
                    cout<<0<<endl;
                    return 0;
                }
                v.push_back(sum*2);
            }
            else if(c == ']'){
                if(pop == -2){
                    cout<<0<<endl;
                    return 0;
                }
                v.push_back(sum*3);
            }
        }
    }
    sum = 0;
    while(!v.empty()){
        int back = v.back();
        if(back<0){
            cout<<0<<endl;
            return 0;
        }
        sum += back;
        v.pop_back();
    }
    cout<<sum<<endl;
}
