#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main(void) {
    char s[105];
    scanf("%s", s);

    int cnt[26] = { 0 };
    for (int i = 0; s[i]; i++)
        cnt[s[i] - 'a']++;

    int maxn = 0, minn = 1000;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] > maxn) maxn = cnt[i];
        if (cnt[i] < minn) minn = cnt[i];
    }

    int d = maxn - minn;
    if (isPrime(d))
        printf("Lucky Word\n%d\n", d);
    else
        printf("No Answer\n0\n");
    return 0;
}