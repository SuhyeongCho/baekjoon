#include <iostream>
#include <vector>


using namespace std;

int main() {
    int N, W, L;
    cin >> N >> W >> L;

    vector<int> arr(N);
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &arr[i]);
    }

    int t = 0;
    int sum = 0;
    int here = 0;
    vector< pair<int, int> > onBridge;
    while(true) {

        int siz = onBridge.size();
        for (int i = 0 ; i < siz ; i++) {
            onBridge[i].second--;
        }
        if (siz && onBridge.front().second == 0) {
            int nhere = onBridge.front().first;
            for (int i = 0 ; i < siz - 1 ; i++) {
                onBridge[i] = onBridge[i + 1];
            }
            onBridge.pop_back();
            sum -= arr[nhere];
            if (nhere == N - 1) break;
        }

        if (here < N && sum + arr[here] <= L) {
            sum += arr[here];
            onBridge.push_back(make_pair(here,W));
            here++;
        }
        
        t++;
    }


    cout << t + 1 << endl;
    return 0;
}