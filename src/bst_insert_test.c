#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_insert(t_btree *root, int item, int napr);

int main() {
    // int (*cmpf)(int, int) = &compare;
    t_btree *root = bstree_create_node(4);
    // bstree_insert(root, 7, cmpf);
    test_insert(root, 6, 1);
    free(root->right);
    free(root);
    printf("\n");
    root = bstree_create_node(10);
    test_insert(root, 2, 0);
    free(root->left);
}

void test_insert(t_btree *root, int item, int napr) {
    int (*cmpf)(int, int) = &compare;
    printf("%d\n", item);
    bstree_insert(root, item, cmpf);
    printf(" %d \n", root->item);
    if (napr == 1)
        printf("NULL %d\n", root->right->item);
    else
        printf("%d NULL\n", root->left->item);
    if ((napr == 1 && root->right->item == item) || (napr == 0 && root->left->item == item)) {
        printf("SUCCESS");
    } else
        printf("FAIL");
}