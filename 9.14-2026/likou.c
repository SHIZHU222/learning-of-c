#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

typedef struct Node {
    int key;
    int val;
    struct Node* next;
} Node;

int subarraySum(int* nums, int numsSize, int k) {
    Node* table[1000] = { 0 };

    int get(int key) {
        int h = (unsigned)(key) % 1000;
        for (Node* p = table[h]; p; p = p->next)
            if (p->key == key) return p->val;
        return 0;
    }
    void put(int key, int val) {
        int h = (unsigned)(key) % 1000;
        for (Node* p = table[h]; p; p = p->next)
            if (p->key == key) { p->val = val; return; }
        Node* nd = malloc(sizeof(Node));
        nd->key = key; nd->val = val; nd->next = table[h]; table[h] = nd;
    }

    put(0, 1);           // 前缀和为 0 出现一次
    int sum = 0, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans += get(sum - k);  // 找到 sum-k 的次数
        put(sum, get(sum) + 1);
    }
    return ans;
}