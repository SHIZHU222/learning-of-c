#include <stdio.h>

int main() {
    char s[260];
    int v[3] = { 0 };                 // v[0]=a, v[1]=b, v[2]=c
    scanf("%s", s);

    for (int i = 0; s[i]; i++) {
        if (s[i] == ':' && s[i + 1] == '=') {
            int t = s[i - 1] - 'a';              // 目标变量索引
            char src = s[i + 2];                 // 来源
            if (src >= '0' && src <= '9')
                v[t] = src - '0';                
            else
                v[t] = v[src - 'a'];             
        }
    }
    printf("%d %d %d\n", v[0], v[1], v[2]);
    return 0;
}