#define _CRT_SECURE_NO_WARNINGS 
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(200 * sizeof(int));   // 按题目规模分配
    *returnSize = 0;
    if (root == NULL) return res;

    struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            if (i == levelSize - 1) res[(*returnSize)++] = node->val;  // 该层最后一个
            if (node->left)  queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
    }

    free(queue);
    return res;
}