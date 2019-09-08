#include <iostream>
#include <queue>
#include <cmath>

using namespace std;



int main() {
    int N; cin >> N;
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (int i = 0 ; i < N ; i++) {
        int d; scanf("%d",&d);
        
        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(d);
        } else {
            maxHeap.push(d);
        }
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxValue = maxHeap.top();
            int minValue = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minValue);
            minHeap.push(maxValue);
        }
        
        printf("%d\n",maxHeap.top());
    }
    return 0;
}



