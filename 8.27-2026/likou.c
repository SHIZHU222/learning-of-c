#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 递归生成 [start, end] 的所有 BST
struct TreeNode** gen(int start, int end, int* size) {
    if (start > end) {
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[0] = NULL;
        *size = 1;
        return res;
    }
    int cap = 0;
    *size = 0;
    struct TreeNode** res = NULL;
    for (int i = start; i <= end; i++) {
        int ls = 0, rs = 0;
        struct TreeNode** left = gen(start, i - 1, &ls);
        struct TreeNode** right = gen(i + 1, end, &rs);
        for (int a = 0; a < ls; a++) {
            for (int b = 0; b < rs; b++) {
                struct TreeNode* root = newNode(i);
                root->left = left[a];
                root->right = right[b];
                if (*size == cap) {
                    cap = cap ? cap * 2 : 4;
                    res = (struct TreeNode**)realloc(res, sizeof(struct TreeNode*) * cap);
                }
                res[(*size)++] = root;
            }
        }
        free(left);
        free(right);
    }
    return res;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return gen(1, n, returnSize);
}