#define _CRT_SECURE_NO_WARNINGS 
//P1219
#include <stdio.h>

int n, cnt = 0, mask;
int pos[15];

void dfs(int row, int cols, int d1, int d2) {
    if (row > n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 1; i <= n; i++)
                printf("%d%c", pos[i], i == n ? '\n' : ' ');
        }
        return;
    }
    int avail = mask & ~(cols | d1 | d2);       /* 还能放的列 */
    while (avail) {
        int bit = avail & (-avail);            /* 最低位的 1 */
        avail ^= bit;
        pos[row] = __builtin_ctz(bit) + 1;     /* 列号 */
        dfs(row + 1, cols | bit,
            ((d1 | bit) << 1) & mask,
            (d2 | bit) >> 1);
    }
}

int main(void) {
    scanf("%d", &n);
    mask = (1 << n) - 1;
    dfs(1, 0, 0, 0);
    printf("%d\n", cnt);
    return 0;
}