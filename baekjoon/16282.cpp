#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int N;
    scanf("%lld", &N);

    long long count = 1;

    while(count <= 100) {
        long long int result = N - pow(2, count + 1) * (count + 1);
        if (result < 0) break;
        count++;
    }

    printf("%lld\n", count);

    return 0;
}
