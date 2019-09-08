#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

#define swap(a,b){char c;    c=a;    a=b;    b=c;}
using namespace std;


int main() {
    
    set<string> s;//visited역할
    queue<string> q;//queue
    string start = "";
    string dest = "123456780";
    
    int c;
    for (int i = 0;i < 9;i++)
    {
        scanf(" %d", &c);
        start += c + '0';
    }
    
    s.insert(start);
    q.push(start);
    
    int cnt = 0;
    string cur;
    
    while (!q.empty()) {
        
        int siz = q.size();
        
        for (int i = 0;i < siz;i++) {
            
            
            cur = q.front();q.pop();
            int idx;
            for (int j = 0;j < 9;j++) {
                if (cur[j] == '0') { idx = j; break; }
            }
            
            if (cur == dest) { printf("%d\n", cnt);return 0; }
            
            if (idx % 3 !=2 && idx + 1 < 9) {
                string tmp; tmp = cur;swap(tmp[idx], tmp[idx + 1]);
                if (s.find(tmp) == s.end())
                {
                    q.push(tmp);
                    s.insert(tmp);
                }
            }
            if (idx %3 != 0 && idx - 1 >= 0) {
                string tmp; tmp = cur;swap(tmp[idx], tmp[idx - 1]);
                if (s.find(tmp) == s.end())
                {
                    q.push(tmp);
                    s.insert(tmp);
                }
            }
            if (idx + 3 < 9) {
                string tmp; tmp = cur;swap(tmp[idx], tmp[idx  + 3]);
                if (s.find(tmp) == s.end())
                {
                    q.push(tmp);
                    s.insert(tmp);
                }
            }
            if (idx - 3 >= 0) {
                string tmp; tmp = cur;swap(tmp[idx], tmp[idx - 3]);
                if (s.find(tmp) == s.end())
                {
                    q.push(tmp);
                    s.insert(tmp);
                }
            }
            
        }
        cnt++;
    }
    
    printf("-1\n");
    
    
    
    return 0;
}
