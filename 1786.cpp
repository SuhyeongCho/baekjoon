#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


int main() {
    char t1[1000002],t2[1000002];
    fgets(t1,1000002,stdin);
    fgets(t2,1000002,stdin);
    
    fflush(stdin);
    
    t1[strlen(t1)-1] = '\0';
    t2[strlen(t2)-1] = '\0';

    string T, P;
    vector<int> v;

    
    T = t1;
    P = t2;
    
    int count = 0;
    size_t found = 0;
    
    bool check = true;
    
    while(check) {
        found = T.find(P, found);ㅌ
        if (found != string::npos) {
            count++;
            v.push_back(found+1);
        } else {
            check = false;
        }
        found++;
    }
    
    int siz = v.size();
    cout << siz << endl;
    if (siz) {
        for (int i = 0 ; i < siz ; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
