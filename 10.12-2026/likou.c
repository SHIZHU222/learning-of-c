int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}
#define _CRT_SECURE_NO_WARNINGS 