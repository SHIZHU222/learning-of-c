//P5728
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int a[1005], b[1005], c[1005], sum[1005];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        sum[i] = a[i] + b[i] + c[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (abs(a[i] - a[j]) <= 5 &&
                abs(b[i] - b[j]) <= 5 &&
                abs(c[i] - c[j]) <= 5 &&
                abs(sum[i] - sum[j]) <= 10) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}