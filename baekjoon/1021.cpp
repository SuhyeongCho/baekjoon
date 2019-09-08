#include <iostream>
#include <list>

using namespace std;


int findValueInList(list<int> l, int n) {
    int index = 0;
    for(list<int>::iterator iter = l.begin(); iter != l.end(); iter++) {
        if (*iter == n) return index;
        index++;
    }
    return -1;
}
int main(){
    int N, M; cin >> N >> M;
    int count = 0;
    
    list<int> l;
    for (int i = 1 ; i <= N ; i++) {
        l.push_back(i);
    }
    for (int i = 0 ; i < M ; i++) {
        int d; cin >> d;
        
        int first = findValueInList(l,d);
        int second = l.size() - first;
        
        if (first < second) {
            for (int j = 0 ; j < first ; j++) {
                int d1 = l.front();
                l.pop_front();
                l.push_back(d1);
            }
            count += first;
        } else {
            for (int j = 0 ; j < second ; j++) {
                int d1 = l.back();
                l.pop_back();
                l.push_front(d1);
            }
            count += second;
        }
        l.pop_front();
    }
    cout << count << endl;
    return 0;
}

