#define _CRT_SECURE_NO_WARNINGS 
//P4447
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

static int a[MAXN];
static int heap[MAXN], hn;   /* 小根堆：以"上一个值"结尾的组长度 */
static int tmp[MAXN];

static int cmp(const void* x, const void* y) {
    int u = *(const int*)x, v = *(const int*)y;
    return (u > v) - (u < v);        /* 防溢出，不要直接相减 */
}

static void push(int x) {
    int i = hn++;
    heap[i] = x;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (heap[p] <= heap[i]) break;
        int t = heap[p]; heap[p] = heap[i]; heap[i] = t;
        i = p;
    }
}

static int pop(void) {
    int top = heap[0];
    heap[0] = heap[--hn];
    int i = 0;
    while (1) {
        int l = (i << 1) + 1, r = l + 1, m = i;
        if (l < hn && heap[l] < heap[m]) m = l;
        if (r < hn && heap[r] < heap[m]) m = r;
        if (m == i) break;
        int t = heap[m]; heap[m] = heap[i]; heap[i] = t;
        i = m;
    }
    return top;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);       /* 实力值升序 */

    int ans = n + 1;
    int prev = 0, havePrev = 0;
    int i = 0;

    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;   /* 当前值段 [i, j) */
        int v = a[i], c = j - i;             /* 值 v 出现了 c 次 */

        /* 能与上一个值 v-1 接上的组，取最短的 k 个扩展 */
        int k = 0;
        if (havePrev && v == prev + 1 && hn > 0) {
            k = (c < hn) ? c : hn;
            for (int t = 0; t < k; t++) tmp[t] = pop();
        }

        /* 接不上的组就此定型，用其中最短的更新答案 */
        if (hn > 0 && heap[0] < ans) ans = heap[0];
        hn = 0;

        /* 扩展的组长度 +1；剩余的 c-k 个人各自新开一组（长度 1） */
        for (int t = 0; t < k; t++) push(tmp[t] + 1);
        for (int t = k; t < c; t++) push(1);

        prev = v;
        havePrev = 1;
        i = j;
    }

    if (hn > 0 && heap[0] < ans) ans = heap[0];

    printf("%d\n", ans);
    return 0;
}