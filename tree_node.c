#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"

// 创建一个新节点
TreeNode* createTreeNode(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (!node) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 递归将数组转换为二叉树，index 为当前节点的数组下标
TreeNode* arrayToTree(int* arr, int size, int index) {
    if (index >= size || arr[index] < MIN_VAL || arr[index] > MAX_VAL) {
        return NULL;
    }
    TreeNode* root = createTreeNode(arr[index]);
    root->left  = arrayToTree(arr, size, 2 * index + 1);
    root->right = arrayToTree(arr, size, 2 * index + 2);
    return root;
}

// 中序遍历打印二叉树
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}