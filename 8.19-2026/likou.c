#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    const int* p = *(const int**)a;
    const int* q = *(const int**)b;
    return p[1] - q[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), cmp);

    int count = 1;
    int end = pairs[0][1];
    for (int i = 1; i < pairsSize; i++) {
        if (pairs[i][0] > end) {
            count++;
            end = pairs[i][1];
        }
    }
    return count;
}