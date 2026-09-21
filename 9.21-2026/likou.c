#define _CRT_SECURE_NO_WARNINGS 
//P2141
#include <stdio.h>

int main(void) {
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {          // 枚举目标数 a[i]
        int found = 0;
        for (int j = 0; j < n && !found; j++) {
            if (j == i) continue;          // 加数和被加数不能是目标数自己
            for (int k = 0; k < n && !found; k++) {
                if (k == i || k == j) continue;
                if (a[j] + a[k] == a[i]) found = 1;
            }
        }
        if (found) ans++;
    }

    printf("%d\n", ans);
    return 0;
}
