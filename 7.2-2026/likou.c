#include <stdbool.h>
#include <stdio.h>

bool canMakeArithmeticProgression(int arr[], int n) {
    if (n <= 2) return true;

    // 1. 找 min 和 max
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    if (min == max) return true;           // 全相等

    // 2. 公差不是整数 → 不可能
    if ((max - min) % (n - 1) != 0) return false;

    int d = (max - min) / (n - 1);

    // 3. 检查每个数是否在对应位置上
    bool seen[n];  // 或 int seen[10001] = {0}
    for (int i = 0; i < n; i++) seen[i] = false;

    for (int i = 0; i < n; i++) {
        int diff = arr[i] - min;
        if (diff % d != 0) return false;   // 不是公差的整数倍
        int pos = diff / d;
        if (pos < 0 || pos >= n || seen[pos]) return false; // 重复或越界
        seen[pos] = true;
    }

    return true;
}