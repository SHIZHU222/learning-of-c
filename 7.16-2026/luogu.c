#define _CRT_SECURE_NO_WARNINGS 
//P3741
#include <stdio.h>

int main() {
    int n, ans = 0;
    char s[105];
    scanf("%d%s", &n, s);

    for (int i = 0; i < n - 1; i++)
        if (s[i] == 'V' && s[i + 1] == 'K')
            ans++, s[i] = s[i + 1] = 0;   // 标记已计数

    for (int i = 0; i < n - 1; i++)
        if (s[i] && s[i + 1] && s[i] == s[i + 1]) {  // VV 或 KK
            ans++;
            break;
        }

    printf("%d\n", ans);
}