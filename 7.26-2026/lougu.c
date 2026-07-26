#define _CRT_SECURE_NO_WARNINGS 
//P5015
#include <stdio.h>

int main() {
    char s[105];
    int ans = 0;
    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i]; i++)
        if (s[i] != ' ' && s[i] != '\n')
            ans++;
    printf("%d", ans);
}
//第二种解法
#include <stdio.h>
int main() {
    int c, ans = 0;
    while ((c = getchar()) != '\n')
        ans += (c != ' ');
    printf("%d", ans);
}
