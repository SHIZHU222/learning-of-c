#define _CRT_SECURE_NO_WARNINGS 
//P1104
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int y, m, d;
    int idx;   // 原始输入顺序
} Stu;

int cmp(const void* a, const void* b) {
    const Stu* x = (const Stu*)a;
    const Stu* y = (const Stu*)b;
    if (x->y != y->y) return x->y - y->y;   // 年小的（更老）在前
    if (x->m != y->m) return x->m - y->m;
    if (x->d != y->d) return x->d - y->d;
    return y->idx - x->idx;                 // 同龄：输入靠后的先输出
}

int main(void) {
    int n;
    scanf("%d", &n);

    Stu* s = (Stu*)malloc(sizeof(Stu) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", s[i].name, &s[i].y, &s[i].m, &s[i].d);
        s[i].idx = i;
    }

    qsort(s, n, sizeof(Stu), cmp);

    for (int i = 0; i < n; i++) printf("%s\n", s[i].name);
    free(s);
    return 0;
}
