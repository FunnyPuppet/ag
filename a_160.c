#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *la = headA;
    struct ListNode *lb = headB;

    int cnt = 0;
    while (la != lb) {
        if (cnt > 2) {
            return NULL;
        }
        if (la->next != NULL) {
            la = la->next;
        } else {
            la = headB;
            cnt++;
        }
        if (lb->next != NULL) {
            lb = lb->next;
        } else {
            lb = headA;
            cnt++;
        }
    }

    return la;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int len = sizeof(nums) / sizeof(nums[0]);

    int res = getIntersectionNode(NULL, NULL);

    printf("%d", res);

    return 0;
}
