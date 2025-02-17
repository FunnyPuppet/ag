#include <stdlib.h>
#include <stdio.h>
#include "list_node.h"

struct ListNode* createNode(const int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    if (node == NULL) {
        exit(1);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* arrayToLinkedList(const int* arr, const int size) {
    if (arr == NULL || size <= 0) {
        return NULL;
    }
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}


