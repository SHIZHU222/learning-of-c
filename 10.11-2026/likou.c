#define _CRT_SECURE_NO_WARNINGS 
void inorder(struct TreeNode* root, int* res, int* idx) {
    if (root == NULL) return;
    inorder(root->left, res, idx);
    res[(*idx)++] = root->val;
    inorder(root->right, res, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}