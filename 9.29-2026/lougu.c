#define _CRT_SECURE_NO_WARNINGS 
//P1068
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int score;
} Player;

int cmp(const void* a, const void* b) {
    const Player* x = (const Player*)a;
    const Player* y = (const Player*)b;
    if (x->score != y->score) return y->score - x->score; // 成绩降序
    return x->id - y->id;                                 // 报名号升序
}

int main(void) {
    int n, m;
    Player p[5000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d %d", &p[i].id, &p[i].score);

    qsort(p, n, sizeof(Player), cmp);

    int num = m * 3 / 2;          // 计划人数的 150% 向下取整
    int line = p[num - 1].score;  // 第 num 名的分数

    int cnt = 0;
    while (cnt < n && p[cnt].score >= line) cnt++;

    printf("%d %d\n", line, cnt);
    for (int i = 0; i < cnt; i++) printf("%d %d\n", p[i].id, p[i].score);

    return 0;
}