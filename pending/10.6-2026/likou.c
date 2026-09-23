#define _CRT_SECURE_NO_WARNINGS 
//P102
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (!root) return NULL;

    struct TreeNode** q = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;

    int** ans = (int**)malloc(2000 * sizeof(int*));
    int* cols = (int*)malloc(2000 * sizeof(int));

    while (head < tail) {
        int n = tail - head;                       // 当前层节点数
        int* level = (int*)malloc(n * sizeof(int));
        cols[*returnSize] = n;

        for (int i = 0; i < n; i++) {
            struct TreeNode* node = q[head++];
            level[i] = node->val;
            if (node->left)  q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }

        ans[*returnSize] = level;
        (*returnSize)++;
    }

    free(q);
    *returnColumnSizes = cols;
    return ans;
}