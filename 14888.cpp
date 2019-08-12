#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool isVisited[12];
char op[12];
int digit[12];

vector<char> v_op;
vector<long long int> result;

void cal() {
    long long int d = digit[0];
    for (int i = 0 ; i < N - 1 ; i++) {
        switch (v_op[i]) {
            case '+':
            d = d + digit[i + 1];
            break;
            case '-':
            d = d - digit[i + 1];
            break;
            case '*':
            d = d * digit[i + 1];
            break;
            case '/':
            d = d / digit[i + 1];
            break;
        }
    }
    result.push_back(d);
}

void fc(int pos) {
    if (pos >= N - 1) {
        cal();
        return;
    }

    for (int i = 0 ; i < N - 1 ; i++) {
        if (isVisited[i]) continue;
        isVisited[i] = true;
        v_op.push_back(op[i]);
        fc(pos + 1);
        v_op.pop_back();
        isVisited[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &digit[i]);
    }

    int d;
    int pos = 0;
    scanf("%d", &d);
    for (int i = 0 ; i < d ; i++) {
        op[pos++] = '+';
    }
    scanf("%d", &d);
    for (int i = 0 ; i < d ; i++) {
        op[pos++] = '-';
    }
    scanf("%d", &d);
    for (int i = 0 ; i < d ; i++) {
        op[pos++] = '*';
    }
    scanf("%d", &d);
    for (int i = 0 ; i < d ; i++) {
        op[pos++] = '/';
    }

    fc(0);

    sort(result.begin(), result.end());
    cout << result[result.size() - 1] << endl;
    cout << result[0] << endl;

    return 0;
}
