#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>
#include <limits.h>

bool valid(struct TreeNode* root, long long low, long long high) {
    if (root == NULL) return true;
    if (root->val <= low || root->val >= high) return false;
    return valid(root->left, low, root->val) &&
        valid(root->right, root->val, high);
}

bool isValidBST(struct TreeNode* root) {
    return valid(root, LLONG_MIN, LLONG_MAX);
}