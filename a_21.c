#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* root = malloc(sizeof(struct ListNode));
    root->next = NULL;
    struct ListNode* cur = root;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    if (list1 != NULL) {
        cur->next = list1;
    }
    if (list2 != NULL) {
        cur->next = list2;
    }

    struct ListNode* result = root->next;
    free(root);

    return result;
}

int main() {
    return 0;
}

