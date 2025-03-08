#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode** nodes = malloc(sizeof(struct ListNode*) * 50000);
    int idx = 0;
    while (cur != NULL) {
        nodes[idx++] = cur;
        cur = cur->next;
    }

    int l = 1, r = idx - 1;
    cur = head;
    while (l < r) {
        cur->next = nodes[r--];
        cur = cur->next;
        if (l < r) {
            cur->next = nodes[l++];
            cur = cur->next;
        }
    }
    cur->next = NULL;
}

int main() {

    return 0;
}