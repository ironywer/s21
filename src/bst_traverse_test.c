#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree *root;
    root = bstree_create_node(10);
    int (*cmpf)(int, int) = &compare;
    bstree_insert(root, 33, cmpf);
    bstree_insert(root, 1, cmpf);
    bstree_insert(root, 5, cmpf);
    bstree_insert(root, 3, cmpf);
    bstree_insert(root, 2524, cmpf);
    bstree_insert(root, 2, cmpf);

    bstree_apply_infix(root, applyf);
    printf("\b\n");
    bstree_apply_prefix(root, applyf);
    printf("\b\n");
    bstree_apply_postfix(root, applyf);
    printf("\b");
    destroy(root);
    return 0;
}