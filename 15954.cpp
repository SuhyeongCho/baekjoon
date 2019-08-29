#include <iostream>
#include <cmath>
#include <algorithm>
#include <float.h>


using namespace std;

long long int psum[501];
long long int dpsum[501];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1 ; i <= N ; i++) {
        long long int d = 0;
        scanf("%lld", &d);
        psum[i] = psum[i - 1] + d;
        dpsum[i] = dpsum[i - 1] + (d * d);
    }


    long double minValue = LDBL_MAX;
    for (int i = K ; i <= N ; i++) {
        for (int s = 1 ; s <= N - i + 1 ; s++) {
            int e = s + i - 1;
            long double mean = (long double)(psum[e] - psum[s - 1]) / i;
            long double dmean = (long double)(dpsum[e] - dpsum[s - 1]) / i;

            long double var = dmean - (mean * mean);

            minValue = min(minValue, sqrt(var));
        }
    }
    printf("%.11Lg\n", minValue);
    return 0;
}