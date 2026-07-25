#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    double best = 0;
    for (int i = 0; i < n; i++) {
        int score, sum = 0, hi = 0, lo = 10;
        for (int j = 0; j < m; j++) {
            scanf("%d", &score);
            sum += score;
            hi = max(hi, score);
            lo = min(lo, score);
        }
        double avg = (sum - hi - lo) * 1.0 / (m - 2);
        if (avg > best) best = avg;
    }
    printf("%.2f\n", best);
    return 0;
}