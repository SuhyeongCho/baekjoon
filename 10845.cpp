#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
    int N; cin >> N;
    queue<int> q;
    for(int i = 0 ; i < N ; i++) {
        char command[6];
        cin >> command;
        if(!strcmp(command, "push")){
            int x; cin >> x;
            q.push(x);
        }
        else if(!strcmp(command,"pop")) {
            if (q.size()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << -1 << endl;
            }
        }
        else if(!strcmp(command,"size")) {
            cout << q.size() << endl;
        }
        else if(!strcmp(command,"empty")) {
            cout << q.empty() << endl;
        }
        else if(!strcmp(command,"front")) {
            if (q.size()) {
                cout << q.front() << endl;
            } else {
                cout << -1 << endl;
            }
        }
        else if(!strcmp(command,"back")) {
            if (q.size()) {
                cout << q.back() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
