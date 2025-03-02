#ifndef TREE_NODE_H
#define TREE_NODE_H

#define MAX_VAL 1000
#define MIN_VAL -1000

// 定义二叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int val);

TreeNode* arrayToTree(int* arr, int size, int index);

void inorderTraversal(TreeNode* root);

#endif //TREE_NODE_H
