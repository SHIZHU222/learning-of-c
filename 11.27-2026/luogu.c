#define _CRT_SECURE_NO_WARNINGS 
//P3613
#include <stdio.h>
#include <stdlib.h>

#define MAXQ 100005

int typ[MAXQ];
int qi[MAXQ], qj[MAXQ];
int qk[MAXQ];

long long keys[MAXQ];

/* 构造唯一键：j <= 100000 < 100001 */
long long makeKey(int i, int j) {
    return (long long)i * 100001LL + j;
}

int cmpLL(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);

    int K = 0;
    for (int t = 0; t < q; t++) {
        scanf("%d", &typ[t]);
        if (typ[t] == 1) {
            scanf("%d %d %d", &qi[t], &qj[t], &qk[t]);
        }
        else {
            scanf("%d %d", &qi[t], &qj[t]);
            qk[t] = 0;
        }
        keys[K++] = makeKey(qi[t], qj[t]);
    }

    /* 排序 + 去重 */
    qsort(keys, K, sizeof(long long), cmpLL);
    int U = 0;
    for (int t = 0; t < K; t++) {
        if (t == 0 || keys[t] != keys[t - 1]) {
            keys[U++] = keys[t];
        }
    }

    /* 离线处理，val 初始化为 0，正好对应「空格子」 */
    int* val = (int*)calloc(U, sizeof(int));

    for (int t = 0; t < q; t++) {
        long long key = makeKey(qi[t], qj[t]);

        /* 二分查找 key 的下标 */
        int lo = 0, hi = U - 1, pos = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (keys[mid] == key) {
                pos = mid;
                break;
            }
            else if (keys[mid] < key) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        if (typ[t] == 1) {
            val[pos] = qk[t];       /* k = 0 时相当于清空 */
        }
        else {
            printf("%d\n", val[pos]);
        }
    }

    free(val);
    return 0;
}