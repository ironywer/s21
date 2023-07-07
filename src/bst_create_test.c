#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_node(int d);

int main() {
    test_node(10);
    printf("\n");
    test_node(5);
    return 0;
}

void test_node(int d) {
    printf("Входные  - %d\n", d);
    t_btree *head = bstree_create_node(d);
    printf("Выходные:  item - %d, left - NULL, right - NULL\n", head->item);
    if (head->item == d && head->left == NULL && head->right == NULL) {
        printf("SUCCESS");
    } else
        printf("FAIL");
    free(head);
}