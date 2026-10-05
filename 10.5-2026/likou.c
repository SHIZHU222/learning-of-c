#define _CRT_SECURE_NO_WARNINGS 
//P543
int dfs(struct TreeNode* root, int* ans) {
    if (root == NULL) return 0;
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    int d = l + r;          // 经过当前节点的路径边数
    if (d > *ans) *ans = d;
    return 1 + (l > r ? l : r);   // 返回当前子树高度（以边数计）
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}