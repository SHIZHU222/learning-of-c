#define _CRT_SECURE_NO_WARNINGS 
//P226
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);

    return root;
}