#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

// 主函数
int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *node_1 = malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = node_1;

    node_1->val = 2;
    node_1->next = head;

    bool flag = hasCycle(head);

    printf("%d", flag);

    free(node_1);
    free(head);

    return 0;
}
