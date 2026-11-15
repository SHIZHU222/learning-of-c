#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

/* 整数哈希（开放寻址、线性探测） */
static unsigned hashInt(int x) {
    unsigned h = (unsigned)x;
    h ^= h >> 16;
    h *= 0x45d9f3bU;
    h ^= h >> 16;
    h *= 0x45d9f3bU;
    h ^= h >> 16;
    return h;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    /* ---------- 1. 哈希表统计频率 ---------- */
    int hsize = 1;
    while (hsize < numsSize * 2 + 16) hsize <<= 1;   /* 保证负载因子 < 0.5 */

    int* keys = (int*)malloc(hsize * sizeof(int));
    int* cnt = (int*)calloc(hsize, sizeof(int));   /* 0 表示空槽 */

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        unsigned h = hashInt(x) & (unsigned)(hsize - 1);
        while (cnt[h] && keys[h] != x)
            h = (h + 1) & (unsigned)(hsize - 1);     /* 线性探测 */
        if (cnt[h] == 0) keys[h] = x;
        cnt[h]++;
    }

    /* ---------- 2. 收集去重后的元素及其频率 ---------- */
    int* vals = (int*)malloc(numsSize * sizeof(int));
    int* freq = (int*)malloc(numsSize * sizeof(int));
    int D = 0;                                       /* 不同元素个数 */

    for (int h = 0; h < hsize; h++) {
        if (cnt[h] > 0) {
            vals[D] = keys[h];
            freq[D] = cnt[h];
            D++;
        }
    }

    /* ---------- 3. 桶排序：以频率为下标 ---------- */
    int* head = (int*)calloc(numsSize + 1, sizeof(int)); /* 桶头：存 i+1，0 表示空 */
    int* nxt = (int*)malloc(D * sizeof(int));           /* 链表 next */

    for (int i = 0; i < D; i++) {
        int f = freq[i];
        nxt[i] = head[f];
        head[f] = i + 1;
    }

    /* ---------- 4. 从高频往低频取 k 个 ---------- */
    int* res = (int*)malloc(k * sizeof(int));
    int got = 0;

    for (int f = numsSize; f >= 1 && got < k; f--) {
        for (int p = head[f]; p && got < k; p = nxt[p - 1]) {
            res[got++] = vals[p - 1];
        }
    }

    *returnSize = got;

    free(keys); free(cnt); free(vals); free(freq); free(head); free(nxt);
    return res;
}