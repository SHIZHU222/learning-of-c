#define _CRT_SECURE_NO_WARNINGS 
//P101
bool isSymmetric(struct TreeNode* root) {
    struct TreeNode** q = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    q[tail++] = root;
    q[tail++] = root;

    while (head < tail) {
        struct TreeNode* u = q[head++];
        struct TreeNode* v = q[head++];
        if (u == NULL && v == NULL) continue;
        if (u == NULL || v == NULL) return false;
        if (u->val != v->val) return false;
        q[tail++] = u->left;
        q[tail++] = v->right;
        q[tail++] = u->right;
        q[tail++] = v->left;
    }
    free(q);
    return true;
}