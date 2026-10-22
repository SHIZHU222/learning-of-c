#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

struct TreeNode* build(int* preorder, int* inorder, int pStart, int pEnd,
    int inStart, int inEnd) {
    if (pStart > pEnd) return NULL;

    int rootVal = preorder[pStart];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;

    int idx = inStart;
    while (inorder[idx] != rootVal) idx++;      // 在中序中找根
    int leftSize = idx - inStart;               // 左子树节点数

    root->left = build(preorder, inorder, pStart + 1, pStart + leftSize,
        inStart, idx - 1);
    root->right = build(preorder, inorder, pStart + leftSize + 1, pEnd,
        idx + 1, inEnd);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
    int* inorder, int inorderSize) {
    return build(preorder, inorder, 0, preorderSize - 1, 0, inorderSize - 1);
}