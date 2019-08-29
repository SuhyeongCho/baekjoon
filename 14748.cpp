#include <iostream>
#include <vector>
#include <string>

using namespace std;

void invalid() {
    cout << -1 << endl;
    exit(0);
}

string removeSpaces(string str) { 
    int count = 0; 
    string s;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            s += str[i];
        }
    }
    return s;
} 

int main() {
    int W = 0, V = 0, EF = 0, EB = 0;
    int S = 0, B = 0, L = 0;
    int C;

    cin >> W;
    string s = "", tmp;
    getchar();
    getline(cin, tmp);
    int tmplen = tmp.length();
    for (int i = 0 ; i < tmplen ; i++) {
        if (tmp[i] != ' ') {
            s += tmp[i];
        }
    }

    vector<char> v;

    int len = s.length();
    for (int i = 0 ; i < len ; i++) {
        switch (s[i]) {
            case 'S':
                if (i && (s[i - 1] == ')' || s[i - 1] == ']' || s[i - 1] == 'S' || s[i - 1] == 'L' || s[i - 1] == 'B')) invalid();
                S++;
                break;
            case 'L':
                if (i && (s[i - 1] == ')' || s[i - 1] == ']' || s[i - 1] == 'S' || s[i - 1] == 'L' || s[i - 1] == 'B')) invalid();
                if (i != len - 1 && s[i + 1] != '('&&s[i + 1] != '[') invalid();
                L++;
                break;
            case 'B':
                if (i && (s[i - 1] == ')' || s[i - 1] == ']' || s[i - 1] == 'S' || s[i - 1] == 'L' || s[i - 1] == 'B')) invalid();
                if (i != len - 1 && s[i + 1] != '('&&s[i + 1] != '[') invalid();
                B++;
                break;
            case ',':
                if (i && s[i - 1] != ']' && s[i - 1] != ')' && s[i - 1] != 'S') invalid();
                break;
            case '[':
                if (i && s[i - 1] != 'L' && s[i - 1] != 'B') invalid();
                v.push_back('[');
                break;
            case ']':
                if (i && s[i - 1] != 'S' && s[i - 1] != ')' && s[i - 1] != ']') invalid();
                if (v.size() && v.back() == '[') v.pop_back();
                else invalid();
                break;
            case '(':
                if (i && s[i - 1] != 'L' && s[i - 1] != 'B') invalid();
                v.push_back('(');
                break;
            case ')':
                if (i && s[i - 1] != 'S' && s[i - 1] != ')' && s[i - 1] != ']') invalid();
                if (v.size() && v.back() == '(') v.pop_back();
                else invalid();
                break;
            default:
                invalid();
        }
    }

    if (v.size()) invalid();
    if (s[0] != 'S' && s[0] != 'L' && s[0] != 'B') invalid();
    if (s[len - 1] != ')' && s[len - 1] != ']' && s[len - 1] != 'S') invalid();



    V = S + 2 * B + 2 * L;
    EF = V - 1 + B;
    EB = L;

    C = EF + W * EB - V + 2;

    cout << C << endl;

    return 0;
}