#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 第一次遍历：从低位加 1
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;          // 没有连续进位，直接返回
        }
        digits[i] = 0;              // 当前位是 9，变 0，进位继续
    }

    // 能走到这里说明全 9，如 999 → 1000
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 0; i < digitsSize; i++)
        result[i + 1] = 0;

    *returnSize = digitsSize + 1;
    return result;
}