#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"
#include "tree_node.h"

struct ListNode* getMid(struct ListNode* left, struct ListNode* right) {
    struct ListNode* fast = left;
    struct ListNode* slow = left;

    while (fast != right && fast->next != right) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

struct TreeNode* build(struct ListNode* left, struct ListNode* right) {
    if (left == right) {
        return NULL;
    }

    struct ListNode* mid = getMid(left, right);
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = build(left, mid);
    root->right = build(mid->next, right);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return build(head, NULL);
}

int main() {

    return 0;
}