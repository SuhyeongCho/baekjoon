#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v;
    for(int i = 0 ; i < N ; i++) {
        char command[6];
        cin >> command;
        if(!strcmp(command, "push")){
            int x; cin >> x;
            v.push_back(x);
        }
        else if(!strcmp(command,"pop")) {
            if (v.size()) {
                cout << v.back() << endl;
                v.pop_back();
            } else {
                cout << -1 << endl;
            }
        }
        else if(!strcmp(command,"size")) {
            cout << v.size() << endl;
        }
        else if(!strcmp(command,"empty")) {
            cout << v.empty() << endl;
        }
        else if(!strcmp(command,"top")) {
            if (v.size()) {
                cout << v.back() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
