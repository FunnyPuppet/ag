#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "list_node.h"

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *cur = head->next;

    while (cur->next != NULL) {
        if(cur->val != 0) {
            p->val += cur->val;
            cur = cur->next;
        } else {
            p = p->next;
            p->val = 0;
            cur = cur->next;
        }
    }
    p->next = NULL;

    return head;
}

int main() {

    return 0;
}