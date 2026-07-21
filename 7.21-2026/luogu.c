#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int x, y, cnt = 0, years[1420];
    scanf("%d%d", &x, &y);

    for (int i = x; i <= y; i++)
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            years[cnt++] = i;

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d ", years[i]);
    return 0;
}