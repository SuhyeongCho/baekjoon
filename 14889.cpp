#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[22][22];

vector<int> team;
bool isVisited[22];

vector<int> result;


void fc(int pos) {
    if (team.size() == N / 2 + 1) {
        int s = 0, l = 0;
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                if (isVisited[i] && isVisited[j]) s += arr[i][j];
                if (!isVisited[i] && !isVisited[j]) l += arr[i][j];
            }
        }
        result.push_back(abs(s - l));
        return;
    }

    for (int i = team[pos - 1] + 1 ; i < N ; i++) {
        if(isVisited[i]) continue;
        isVisited[i] = true;
        team.push_back(i);
        fc(pos + 1);
        team.pop_back();
        isVisited[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    team.push_back(-1);
    fc(1);

    sort(result.begin(), result.end());
    cout << result[0] << endl;

    return 0;
}