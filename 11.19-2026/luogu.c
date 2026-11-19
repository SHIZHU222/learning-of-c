#define _CRT_SECURE_NO_WARNINGS 
//p1518
#include <stdio.h>

char map[10][11];

/* 方向：0 北  1 东  2 南  3 西（顺时针） */
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

typedef struct {
    int x, y, d;
} Entity;

/* 走一步：能走就走，不能走就顺时针转 90 度 */
void moveOne(Entity* e) {
    int nx = e->x + dx[e->d];
    int ny = e->y + dy[e->d];

    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx][ny] != '*') {
        e->x = nx;
        e->y = ny;
    }
    else {
        e->d = (e->d + 1) % 4;
    }
}

int main(void) {
    for (int i = 0; i < 10; i++) scanf("%s", map[i]);

    Entity f, c;
    f.d = c.d = 0;                 /* 初始都朝北 */

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'F') { f.x = i; f.y = j; }
            else if (map[i][j] == 'C') { c.x = i; c.y = j; }
        }

    /* 状态压缩：10*10*4*10*10*4 = 160000 */
    static char vis[10 * 10 * 4 * 10 * 10 * 4];

    int minute = 0;

    for (;;) {
        /* 把“当前状态”压成一个整数下标 */
        int idx = ((((f.x * 10 + f.y) * 4 + f.d) * 10 + c.x) * 10 + c.y) * 4 + c.d;

        if (vis[idx]) {            /* 状态重复 → 永远不会相遇 */
            printf("0\n");
            return 0;
        }
        vis[idx] = 1;

        /* 双方同时移动 */
        moveOne(&f);
        moveOne(&c);
        minute++;

        if (f.x == c.x && f.y == c.y) {
            printf("%d\n", minute);
            return 0;
        }
    }
}