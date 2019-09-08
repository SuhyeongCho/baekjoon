#include<iostream>

using namespace std;

int N;
int arr[20];
int cnt;

bool check(int n) {
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == arr[n]) return false;
        if (abs(arr[i] - arr[n]) == abs(n - i)) return false;
    }
    return true;
}
void fc(int n) {
    if (!check(n)) return;
    
    if (n == N - 1) {
        cnt++;
        return;
    }
    
    for (int i = 0 ; i < N ; i++) {
        arr[n + 1] = i;
        fc(n+1);
    }

}
int main(){
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        arr[0] = i;
        fc(0);
    }

    cout << cnt << endl;
 
    return 0;
}





