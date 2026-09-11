#define _CRT_SECURE_NO_WARNINGS 
//P1093
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;     // 学号
    int total;  // 总分
    int ch;     // 语文
} Stu;

int cmp(const void* pa, const void* pb) {
    const Stu* a = (const Stu*)pa;
    const Stu* b = (const Stu*)pb;
    if (a->total != b->total) return b->total - a->total;   // 总分降序
    if (a->ch != b->ch)       return b->ch - a->ch;         // 语文降序
    return a->id - b->id;                                    // 学号升序
}

int main(void) {
    int n;
    scanf("%d", &n);

    Stu s[301];
    for (int i = 0; i < n; i++) {
        int ch, ma, en;
        scanf("%d %d %d", &ch, &ma, &en);
        s[i].id = i + 1;
        s[i].ch = ch;
        s[i].total = ch + ma + en;
    }

    qsort(s, n, sizeof(Stu), cmp);

    for (int i = 0; i < 5; i++)
        printf("%d %d\n", s[i].id, s[i].total);

    return 0;
}