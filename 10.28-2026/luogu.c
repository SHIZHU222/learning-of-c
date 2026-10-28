#define _CRT_SECURE_NO_WARNINGS 
//P1106
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[260];
    int k;
    if (scanf("%s", s) != 1) return 0;
    scanf("%d", &k);

    int len = strlen(s);
    char stk[260];
    int top = 0;

    for (int i = 0; i < len; i++) {
        while (k > 0 && top > 0 && stk[top - 1] > s[i]) {
            top--;       /* 删掉栈顶较大的数字 */
            k--;
        }
        stk[top++] = s[i];
    }

    /* 若还需删除，从末尾删 */
    while (k > 0) {
        top--;
        k--;
    }

    /* 去除前导零 */
    int start = 0;
    while (start < top && stk[start] == '0') start++;

    if (start == top) {
        printf("0\n");
    }
    else {
        stk[top] = '\0';
        printf("%s\n", stk + start);
    }
    return 0;
}