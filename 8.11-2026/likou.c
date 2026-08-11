#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1, j = strlen(b) - 1;
    int maxLen = (i > j ? i : j) + 2;          // 最坏情况：多一位进位
    char* res = (char*)malloc(maxLen + 1);
    res[maxLen] = '\0';

    int carry = 0, k = maxLen - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res[k--] = (sum & 1) + '0';             // sum % 2
        carry = sum >> 1;                       // sum / 2
    }
    return res + k + 1;                         // 跳过未使用的头部
}
//
char* addBinary(char* a, char* b) {
    int i = strlen(a), j = strlen(b), carry = 0, k = 0;
    char* res = (char*)calloc((i > j ? i : j) + 2, 1);

    while (i || j || carry) {
        if (i) carry += a[--i] - '0';
        if (j) carry += b[--j] - '0';
        res[k++] = (carry & 1) + '0';
        carry >>= 1;
    }
    for (int p = 0, q = k - 1; p < q; p++, q--) {  // 反转
        char t = res[p]; res[p] = res[q]; res[q] = t;
    }
    return res;
}