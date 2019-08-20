#include <iostream>
#include <vector>

using namespace std;

int N;

int inorder[100001];
int postorder[100001];

int search(int x) {
    for (int i = 0 ; i < 100000 ; i++) {
        if (inorder[i] == x) return i;
    }
    return -1;
}

void preorder(int is, int ie, int ps, int pe) {

    if (is > ie || ps > pe) return;

    int root = postorder[pe];
    printf("%d ", root);
    int d = search(root);
    preorder(is, d - 1, ps, ps - is + d - 1);
    preorder(d + 1, ie, ps - is + d, pe - 1);
}


int main() {
    cin >> N;
    
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &postorder[i]);
    }

    preorder(0, N - 1, 0, N - 1);
    cout << endl;
    return 0;
}