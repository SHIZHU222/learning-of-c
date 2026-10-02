#define _CRT_SECURE_NO_WARNINGS 
//P104
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}