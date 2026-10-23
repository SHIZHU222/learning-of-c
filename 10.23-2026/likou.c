#define _CRT_SECURE_NO_WARNINGS 
int dfs(struct TreeNode* root, long long target) {
    if (root == NULL) return 0;
    int cnt = 0;
    if (root->val == target) cnt++;
    cnt += dfs(root->left, target - root->val);
    cnt += dfs(root->right, target - root->val);
    return cnt;
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return 0;
    return dfs(root, targetSum)
        + pathSum(root->left, targetSum)
        + pathSum(root->right, targetSum);
}