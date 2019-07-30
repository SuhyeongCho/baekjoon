#include<iostream>
#include<list>
#include<cstring>

using namespace std;

list<int> stringToList(char* s) {
    list<int> l;
    int len = strlen(s);
    int num = 0;
    for (int i = 0 ; i < len ; i++) {
        if (i == 0 && s[i] == '[' && s[i+1] == ']') break;
        if (s[i] == '[') continue;
        if (s[i] == ',' || s[i] == ']') {
            l.push_back(num);
            num = 0;
        }
        else {
            num *= 10;
            num += s[i] - '0';
        }
    }
    return l;
}


int main() {
    int T; cin >> T;
    for (int t = 0 ; t < T ; t++) {
        char p[400001]; scanf("%s",p);
        int N; cin >> N;
        char s[400001]; scanf("%s",s);
        
        list<int> l = stringToList(s);
        
        int len = strlen(p);
        
        int head = 0;
        int tail = 0;
        int reverseCount = 0;
        for (int i = 0 ; i < len ; i++) {
            if (p[i] == 'R') reverseCount++;
            else {
                if (reverseCount % 2) tail++;
                else head++;
            }
        }
        
        if (head + tail > l.size()) {
            printf("error\n");
        } else {
            
            for (int i = 0 ; i < head ; i++) l.pop_front();
            for (int i = 0 ; i < tail ; i++) l.pop_back();

            if (reverseCount % 2) l.reverse();
            
            if (l.size() == 0) cout << "[]" << endl;
            else {
                cout << "[";
                int index = 0;
                for (list<int>::iterator iter = l.begin() ; iter != l.end() ; iter++) {
                    cout << *iter;
                    index++;
                    if (index == l.size()) cout << "]" << endl;
                    else printf(",");
                }
            }
        }
    }

    return 0;
}

