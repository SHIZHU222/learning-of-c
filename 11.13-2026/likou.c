#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)calloc(temperaturesSize, sizeof(int));  /* 自动置 0 */
    int* stk = (int*)malloc(temperaturesSize * sizeof(int)); /* 存下标 */
    int top = 0;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top > 0 && temperatures[i] > temperatures[stk[top - 1]]) {
            int j = stk[--top];          /* 弹出栈顶那天 */
            ans[j] = i - j;              /* 等待的天数 */
        }
        stk[top++] = i;
    }

    *returnSize = temperaturesSize;
    free(stk);
    return ans;
}