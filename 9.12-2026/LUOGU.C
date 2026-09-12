#define _CRT_SECURE_NO_WARNINGS 
//P1157
#include <stdio.h>

int n, r;
int a[30];

void dfs(int pos, int start) {
    if (pos > r) {
        for (int i = 1; i <= r; i++)
            printf("%3d", a[i]);
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++) {
        a[pos] = i;
        dfs(pos + 1, i + 1);
    }
}

int main() {
    scanf("%d%d", &n, &r);
    dfs(1, 1);
    return 0;
}