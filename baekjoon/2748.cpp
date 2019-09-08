#include<iostream>

using namespace std;

long long int fi[100];

int main(){
    
    int n; cin >> n;
    
    fi[0] = 0;
    fi[1] = 1;
    
    for (int i = 2 ; i <= n ; i++) {
        fi[i] = fi[i - 1] + fi[i - 2];
    }
    
    cout << fi[n] << endl;
    
    return 0;
}

