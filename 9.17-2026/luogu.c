#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int dir[100005];
char name[100005][11];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %s", &dir[i], name[i]);

    int pos = 0;
    for (int i = 0; i < m; i++) {
        int a, s;
        scanf("%d %d", &a, &s);
        if (dir[pos] ^ a)          // 方向相反 → 逆时针 → 索引加
            pos = (pos + s) % n;
        else                       // 方向相同 → 顺时针 → 索引减
            pos = (pos - s % n + n) % n;
    }
    printf("%s\n", name[pos]);
    return 0;
