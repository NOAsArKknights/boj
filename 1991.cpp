#include <stdio.h>

char tree[30][2];

void preorder(char node) {
    if (node == '.') return;
    printf("%c",node);
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node][0]);
    printf("%c",node);
    inorder(tree[node][1]);
}

void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    printf("%c",node);
}

int main() {
    int n;
    char p, l, r;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &p, &l, &r);
        tree[p][0] = l;
        tree[p][1] = r;
    }


    preorder('A'); printf("\n");
    inorder('A');  printf("\n");
    postorder('A'); printf("\n");

    return 0;
}
