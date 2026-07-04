#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calPoints(char** ops, int opsSize) {
    int stack[1000];  // 栈，大小够用就行
    int top = 0;

    for (int i = 0; i < opsSize; i++) {
        if (ops[i][0] == '+') {
            int sum = stack[top - 1] + stack[top - 2];
            stack[top++] = sum;
        }
        else if (ops[i][0] == 'D') {
            stack[top++] = stack[top - 1] * 2;
        }
        else if (ops[i][0] == 'C') {
            top--;
        }
        else {
            stack[top++] = atoi(ops[i]);
        }
    }

    int total = 0;
    for (int i = 0; i < top; i++)
        total += stack[i];
    return total;
}