#define _CRT_SECURE_NO_WARNINGS 
//P1303
#include <stdio.h>
#include <string.h>

int main() {
    char a[2010], b[2010];
    scanf("%s %s", a, b);

    char* pa = a, * pb = b;
    while (*pa == '0' && pa[1]) pa++;   // 去掉前导零
    while (*pb == '0' && pb[1]) pb++;

    if (pa[0] == '0' || pb[0] == '0') {
        printf("0\n");
        return 0;
    }

    int la = strlen(pa), lb = strlen(pb);
    int res[4100] = { 0 };

    // 逐位相乘，累加到结果对应位
    for (int i = 0; i < la; i++)
        for (int j = 0; j < lb; j++)
            res[i + j] += (pa[la - 1 - i] - '0') * (pb[lb - 1 - j] - '0');

    // 统一处理进位
    int len = la + lb;
    for (int i = 0; i < len; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }

    // 从最高非零位开始输出
    int pos = len;
    while (pos > 0 && res[pos] == 0) pos--;
    for (int i = pos; i >= 0; i--)
        printf("%d", res[i]);
    printf("\n");

    return 0;
}