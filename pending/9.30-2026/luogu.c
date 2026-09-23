#define _CRT_SECURE_NO_WARNINGS 
//P5143
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point;

int cmp(const void* a, const void* b) {
    const Point* p = (const Point*)a;
    const Point* q = (const Point*)b;
    if (p->z < q->z) return -1;
    if (p->z > q->z) return 1;
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Point* p = (Point*)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        p[i].x = x; p[i].y = y; p[i].z = z;
    }

    qsort(p, n, sizeof(Point), cmp);   // 按高度升序

    double ans = 0.0;
    for (int i = 1; i < n; i++) {
        double dx = p[i].x - p[i - 1].x;
        double dy = p[i].y - p[i - 1].y;
        double dz = p[i].z - p[i - 1].z;
        ans += sqrt(dx * dx + dy * dy + dz * dz);
    }

    printf("%.3f\n", ans);
    free(p);
    return 0;
}