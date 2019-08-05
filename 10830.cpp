#include <iostream>
#include <vector>

using namespace std;

vector< vector<long long int> > arr(5,vector<long long int>(5));
long long int N, B;

void multiplyMatrix(vector< vector<long long int> > A, vector< vector<long long int> > B, vector< vector<long long int> > &C) {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            for (int k = 0 ; k < N ; k++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % 1000) % 1000;
            }
        }
    }
}

void solve(long long int B, vector< vector<long long int> > &C) {
    if (B == 1) {
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                C[i][j] = arr[i][j];
            }
        }
        return;
    }
    vector< vector<long long int> > tmp(5,vector<long long int>(5));
    vector< vector<long long int> > tmp2(5,vector<long long int>(5));
    solve(B / 2, tmp);
    multiplyMatrix(tmp, tmp, tmp2);
    if (B % 2) multiplyMatrix(tmp2, arr, C);
    else C = tmp2;
}

int main() {
    cin >> N >> B;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    

    vector< vector<long long int> > C(5,vector<long long int>(5));

    solve(B, C);

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            printf("%d ", C[i][j] % 1000);
        }
        printf("\n");
    }
    return 0;
}