#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    char g[105][105];
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    int dx[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1,-1, 1,-1, 0, 1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                putchar('*');
            }
            else {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '*')
                        cnt++;
                }
                putchar('0' + cnt);
            }
        }
        putchar('\n');
    }
    return 0;
}