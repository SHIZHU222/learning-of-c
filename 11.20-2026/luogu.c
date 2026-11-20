#define _CRT_SECURE_NO_WARNINGS 
//P2404
#include <stdio.h>

int n;
int a[15];

void dfs(int rem, int minPart, int depth) {
    if (rem == 0) {
        if (depth == 1) return;
        for (int i = 0; i < depth; i++) {
            if (i) putchar('+');
            printf("%d", a[i]);
        }
        putchar('\n');
        return;
    }

    for (int x = minPart; x <= rem; x++) {
        a[depth] = x;
        dfs(rem - x, x, depth + 1);
    }
}

int main(void) {
    scanf("%d", &n);
    dfs(n, 1, 0);
    return 0;
}