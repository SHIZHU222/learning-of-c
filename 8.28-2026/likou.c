#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

// 返回长度为2的数组 [不抢, 抢]，调用方负责 free
int* dfs(struct TreeNode* root) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = res[1] = 0;
    if (root == NULL) return res;

    int* left = dfs(root->left);
    int* right = dfs(root->right);

    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];

    free(left);
    free(right);
    return res;
}

int rob(struct TreeNode* root) {
    int* res = dfs(root);
    int ans = max(res[0], res[1]);
    free(res);
    return ans;
}