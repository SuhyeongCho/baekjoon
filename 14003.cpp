#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int trace[1000001];

int main() {
    int N; cin >> N;

    for (int i = 1 ; i <= N ; i++) {
        scanf("%d", &arr[i]);
    }
    vector<int> v;
    v.push_back(-1987654321);
    for (int i = 1 ; i <= N ; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
            trace[i] = v.size() - 1;
        } else {
            vector<int>::iterator iter = lower_bound(v.begin(),v.end(), arr[i]);
            *iter = arr[i];
            trace[i] = iter - v.begin();
        }
        
    }

    cout << v.size() - 1 << endl;
    
    int current = 0;
    for (int i = 1 ; i <= N ; i++) {
        if (current < trace[i]) current = trace[i];
    }
    
    vector<int> result;
    for (int i = N ; i > 0 ; i--) {
        if (trace[i] == current) {
            result.push_back(arr[i]);
            current--;
        }
    }

    int siz = result.size();
    for (int i = 0 ; i < siz ; i++) {
        printf("%d ", result.back());
        result.pop_back();
    }

    cout << endl;

    return 0;
}