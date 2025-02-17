#ifndef LIST_NODE_H
#define LIST_NODE_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val);

struct ListNode* arrayToLinkedList(const int* arr, int size);

void freeList(struct ListNode* head);

void printList(struct ListNode* head);

#endif
