#include <iostream>

using namespace std;

int tree[26][2];

void preorder(int n) {

    if (n == -1) return;

    printf("%c", n + 'A');
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}

void inorder(int n) {

    if (n == -1) return;

    inorder(tree[n][0]);
    printf("%c", n + 'A');
    inorder(tree[n][1]);
}

void postorder(int n) {

    if (n == -1) return;

    postorder(tree[n][0]);
    postorder(tree[n][1]);
    printf("%c", n + 'A');

}


int main() {
    int N; cin >> N;

    for (int i = 0 ; i < N ; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        tree[a - 'A'][0] = b != '.' ? b - 'A' : -1;
        tree[a - 'A'][1] = c != '.' ? c - 'A' : -1;
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0;
}