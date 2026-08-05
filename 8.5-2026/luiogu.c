#define _CRT_SECURE_NO_WARNINGS 
//P1957
#include <stdio.h>
#include <string.h>

int len(int n) {
    if (n == 0) return 1;
    int c = 0;
    if (n < 0) { c = 1; n = -n; }
    while (n) { c++; n /= 10; }
    return c;
}

int main() {
    int n;
    char op = 0, buf[20];
    scanf("%d", &n);

    while (n--) {
        scanf("%s", buf);
        int a, b;

        if (buf[0] >= 'a' && buf[0] <= 'c') {
            op = buf[0];
            scanf("%d%d", &a, &b);
        }
        else {
            sscanf(buf, "%d", &a);
            scanf("%d", &b);
        }

        int res;
        char sym;
        if (op == 'a') sym = '+', res = a + b;
        else if (op == 'b') sym = '-', res = a - b;
        else sym = '*', res = a * b;

        printf("%d%c%d=%d\n", a, sym, b, res);
        printf("%d\n", len(a) + 1 + len(b) + 1 + len(res));
    }
    return 0;
}