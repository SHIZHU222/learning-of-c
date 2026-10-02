#define _CRT_SECURE_NO_WARNINGS 
//P1088
#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

// 求下一个字典序排列，返回 1 表示成功（题目保证有解）
int nextPerm(int* a, int n) {
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) i--;   // 找第一个下降点
    if (i < 0) return 0;

    int j = n - 1;
    while (a[j] <= a[i]) j--;                 // 找比 a[i] 大的最靠右元素
    swap(&a[i], &a[j]);

    for (int l = i + 1, r = n - 1; l < r; l++, r--)   // 反转后缀
        swap(&a[l], &a[r]);
    return 1;
}

int main(void) {
    int n, m;
    int a[10000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int k = 0; k < m; k++) nextPerm(a, n);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}