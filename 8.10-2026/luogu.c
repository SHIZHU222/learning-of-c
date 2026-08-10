#define _CRT_SECURE_NO_WARNINGS 
//P1304
#include <stdio.h>

int main() {
    int N, p[10001] = { 0 };
    scanf("%d", &N);

    // 埃氏筛
    p[0] = p[1] = 1;
    for (int i = 2; i * i <= N; i++)
        if (!p[i])
            for (int j = i * i; j <= N; j += i)
                p[j] = 1;

    for (int i = 4; i <= N; i += 2) {
        for (int a = 2; a < i; a++) {
            if (!p[a] && !p[i - a]) {
                printf("%d=%d+%d\n", i, a, i - a);
                break;          // 找到第一个就跳出，保证 a 最小
            }
        }
    }
    return 0;
}