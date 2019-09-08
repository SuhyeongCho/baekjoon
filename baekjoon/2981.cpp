#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N; cin >> N;
    
    vector<int> v1(N);
    vector<int> v2(N - 1);

    set<int> s;
    
    for (int i = 0; i < N ; i++) {
        scanf("%d", &v1[i]);
    }
    
    sort(v1.begin(), v1.end());
    
    for (int i = 0; i < N - 1 ; i++) {
        v2[i] = v1[i + 1] - v1[i];
    }
    
    int result = v2[0];
    for (int i = 1 ; i < N - 1 ; i++) {
        result = gcd(result, v2[i]);
    }
    
    for (int i = 2 ; i * i <= result ; i++) {
        if (result % i == 0) {
            s.insert(i);
            s.insert(result / i);
        }
    }
    s.insert(result);
    
    for (set<int>::iterator iter = s.begin() ; iter != s.end() ; iter++) {
        printf("%d ", *iter);
    }
    cout << endl;

    return 0;
}
