#define _CRT_SECURE_NO_WARNINGS 
//P1449
#include <stdio.h>

int main(void) {
    char s[105];
    scanf("%s", s);

    long long st[105];   /* 栈 */
    int top = 0;

    long long num = 0;   /* 正在读取的操作数 */

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            /* 累加多位数 */
            num = num * 10 + (c - '0');
        }
        else if (c == '.') {
            /* 一个操作数结束，入栈 */
            st[top++] = num;
            num = 0;
        }
        else if (c == '@') {
            break;
        }
        else {
            /* 运算符：先弹右操作数，再弹左操作数 */
            long long b = st[--top];
            long long a = st[--top];
            long long r;

            switch (c) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b; break;
            case '/': r = a / b; break;   /* C 的整数除法向 0 取整 */
            default:  r = 0;     break;
            }

            st[top++] = r;
        }
    }

    printf("%lld\n", st[top - 1]);
    return 0;
}