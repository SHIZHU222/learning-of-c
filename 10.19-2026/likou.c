#define _CRT_SECURE_NO_WARNINGS 
void inorder(struct TreeNode* root, int k, int* cnt, int* ans) {
    if (root == NULL || *cnt >= k) return;

    inorder(root->left, k, cnt, ans);

    (*cnt)++;
    if (*cnt == k) {
        *ans = root->val;
        return;
    }

    inorder(root->right, k, cnt, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int cnt = 0, ans = 0;
    inorder(root, k, &cnt, &ans);
    return ans;
}
