#define _CRT_SECURE_NO_WARNINGS 
//P1042
#include <stdio.h>
#include <stdlib.h>

void solve(const char* s, int n, int limit) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') a++;
        else b++;
        if ((a >= limit || b >= limit) && abs(a - b) >= 2) {
            printf("%d:%d\n", a, b);
            a = b = 0;
        }
    }
    printf("%d:%d\n", a, b);
}

int main(void) {
    char s[100005];   // 25 * 2501 ≈ 62525，多留余量
    int n = 0, c;

    while ((c = getchar()) != EOF) {
        if (c == 'E') break;            // 结束，忽略其后所有内容
        if (c == 'W' || c == 'L') s[n++] = c;
    }

    solve(s, n, 11);
    printf("\n");
    solve(s, n, 21);

    return 0;
}