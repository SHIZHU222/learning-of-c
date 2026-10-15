#define _CRT_SECURE_NO_WARNINGS 
//P1803
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Match;

int cmp(const void* x, const void* y) {
    return ((Match*)x)->b - ((Match*)y)->b;
}

int main() {
    int n;
    scanf("%d", &n);

    Match* m = (Match*)malloc(n * sizeof(Match));
    for (int i = 0; i < n; i++)
        scanf("%d %d", &m[i].a, &m[i].b);

    qsort(m, n, sizeof(Match), cmp);

    int cnt = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (m[i].a >= last) {
            cnt++;
            last = m[i].b;
        }
    }

    printf("%d\n", cnt);
    free(m);
    return 0;
}
