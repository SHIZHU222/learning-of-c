#define _CRT_SECURE_NO_WARNINGS 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;   // p、q 在两侧，root 即 LCA
    return left ? left : right;       // 否则在非空的那一侧
}