#define _CRT_SECURE_NO_WARNINGS 
//P108
struct TreeNode* build(int* nums, int left, int right) {
    if (left > right) return NULL;

    int mid = left + (right - left) / 2;   // 取中间元素，避免溢出

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return build(nums, 0, numsSize - 1);
}