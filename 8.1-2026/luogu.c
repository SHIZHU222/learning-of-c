#define _CRT_SECURE_NO_WARNINGS 
//P1151
#include <stdio.h>

int main() {
    int K, found = 0;
    scanf("%d", &K);
    for (int i = 10000; i <= 30000; i++) {
        int a = i / 100, b = i / 10 % 1000, c = i % 1000;
        if (a % K == 0 && b % K == 0 && c % K == 0)
            printf("%d\n", i), found = 1;
    }
    if (!found) printf("No");
    return 0;
}
