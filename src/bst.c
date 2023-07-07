#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
void applyf(int d);
t_btree *bstree_create_node(int item) {
    t_btree *node1 = malloc(sizeof(t_btree));
    node1->item = item;
    node1->left = NULL;
    node1->right = NULL;
    return node1;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *r;
    while (root != NULL) {
        r = root;
        int n = cmpf(item, root->item);
        root = n == 0 ? root->left : root->right;
    }
    root = bstree_create_node(item);
    if (cmpf(item, r->item) == 0) {
        r->left = root;
    } else
        r->right = root;
}

int compare(int a, int b) { return (a > b) ? 1 : 0; }

void applyf(int d) { printf("%d ", d); }

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}
void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_infix(root->left, applyf);
        bstree_apply_infix(root->right, applyf);
    }
}
void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        bstree_apply_infix(root->right, applyf);
        applyf(root->item);
    }
}

void destroy(t_btree *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}