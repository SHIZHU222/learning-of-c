#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int win[34] = { 0 };
    for (int i = 0; i < 7; i++) {
        int x;
        scanf("%d", &x);
        win[x] = 1;
    }

    int prize[8] = { 0 };  /* prize[k] = 中 k 个号码的彩票张数，k=1..7 */
    for (int i = 0; i < n; i++) {
        int match = 0;
        for (int j = 0; j < 7; j++) {
            int x;
            scanf("%d", &x);
            if (win[x]) match++;
        }
        prize[match]++;
    }

    /* 特等奖=7个，一等奖=6个 ... 六等奖=1个 */
    for (int k = 7; k >= 1; k--)
        printf("%d%c", prize[k], k == 1 ? '\n' : ' ');
    return 0;
}