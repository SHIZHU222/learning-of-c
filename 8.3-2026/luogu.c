#define _CRT_SECURE_NO_WARNINGS 
//P1001
#include <stdio.h>
#include <string.h>

int sum[100], fact[100];   // 总和、当前阶乘，低位在前存储

void mul(int* a, int x) {  // 高精度 × 低精度
    int carry = 0;
    for (int i = 0; i < 100; i++) {
        int t = a[i] * x + carry;
        a[i] = t % 10;
        carry = t / 10;
    }
}

void add(int* a, int* b) { // 高精度 + 高精度，结果存回 a
    int carry = 0;
    for (int i = 0; i < 100; i++) {
        int t = a[i] + b[i] + carry;
        a[i] = t % 10;
        carry = t / 10;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    fact[0] = 1;                     // fact = 1 (0!)
    for (int i = 1; i <= n; i++) {
        mul(fact, i);                // fact = i!
        add(sum, fact);              // sum += i!
    }

    int top = 99;
    while (top > 0 && sum[top] == 0) top--;   // 去掉前导零

    for (int i = top; i >= 0; i--)            // 高位在前输出
        printf("%d", sum[i]);
    return 0;
}