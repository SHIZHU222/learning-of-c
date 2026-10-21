#define _CRT_SECURE_NO_WARNINGS 
void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    root->left = NULL;
    root->right = left;              // 左子树接到右指针

    struct TreeNode* p = root;
    while (p->right) p = p->right;   // 走到左子树链表末尾
    p->right = right;                // 原右子树接在末尾
}