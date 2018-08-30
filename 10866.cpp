#include<iostream>
#include<cstring>
#include<list>

using namespace std;


int main(){
    list<int> l;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char command[12];
        cin>>command;
        if(!strcmp(command,"push_front")){
            int x; cin>>x;
            l.push_front(x);
        }
        else if(!strcmp(command,"push_back")){
            int x; cin>>x;
            l.push_back(x);
        }
        else if(!strcmp(command,"pop_front")){
            if(l.size()){
                cout<<l.front()<<endl;
                l.pop_front();
            }else cout<<-1<<endl;
        }
        else if(!strcmp(command,"pop_back")){
            if(l.size()){
                cout<<l.back()<<endl;
                l.pop_back();
            }else cout<<-1<<endl;
        }
        else if(!strcmp(command,"size")) cout<<l.size()<<endl;
        else if(!strcmp(command,"empty")) cout<<l.empty()<<endl;
        else if(!strcmp(command,"front")){
            if(l.size()){
                cout<<l.front()<<endl;
            }else cout<<-1<<endl;
        }
        else if(!strcmp(command,"back")){
            if(l.size()){
                cout<<l.back()<<endl;
            }else cout<<-1<<endl;
        }
    }
}

