#define _CRT_SECURE_NO_WARNINGS 
//p1223
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t;      // 接水时间
    int id;     // 编号
} Person;

int cmp(const void* a, const void* b) {
    Person* pa = (Person*)a;
    Person* pb = (Person*)b;
    if (pa->t != pb->t) return pa->t - pb->t;
    return pa->id - pb->id;              // 时间相同，编号小的在前
}

int main() {
    int n;
    scanf("%d", &n);

    Person p[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].t);
        p[i].id = i + 1;
    }

    qsort(p, n, sizeof(Person), cmp);

    long long total = 0, sum = 0;        // total 总等待时间，sum 前面人的接水时间和
    for (int i = 0; i < n; i++) {
        total += sum;                    // 第 i 个人等待前面所有人的时间和
        sum += p[i].t;
        printf("%d%c", p[i].id, i == n - 1 ? '\n' : ' ');
    }

    printf("%.2f\n", (double)total / n);
    return 0;
}