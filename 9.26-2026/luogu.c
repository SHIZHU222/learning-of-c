#define _CRT_SECURE_NO_WARNINGS 
//P1781
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int bestId = 1;
    char best[101], cur[101];
    scanf("%s", best);

    for (int i = 2; i <= n; i++) {
        scanf("%s", cur);
        int lb = strlen(best), lc = strlen(cur);
        int better = 0;
        if (lc > lb) better = 1;
        else if (lc == lb && strcmp(cur, best) > 0) better = 1;

        if (better) {
            strcpy(best, cur);
            bestId = i;
        }
    }

    printf("%d\n%s\n", bestId, best);
    return 0;
}