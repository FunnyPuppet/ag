#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct ListNode* p = head;

            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}

int main() {

    return 0;
}

