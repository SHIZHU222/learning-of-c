#define _CRT_SECURE_NO_WARNINGS 
//P1554
#include <stdio.h>

int main() {
    int M, N;
    int cnt[10] = { 0 };

    scanf("%d %d", &M, &N);

    for (int i = M; i <= N; i++) {
        int x = i;
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d%c", cnt[i], " \n"[i == 9]);
    }

    return 0;
}