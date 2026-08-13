#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
    int n, m, cnt[1000] = { 0 };
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < cnt[i]; j++)
            printf("%d ", i);
    return 0;
}