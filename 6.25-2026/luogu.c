//P1422
#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    double total = 0;
    if (x <= 150) {
        total = x * 0.4463;
    }
    else if (x <= 400) {
        total = 150 * 0.4463 + (x - 150) * 0.4663;
    }
    else {
        total = 150 * 0.4463 + 250 * 0.4663 + (x - 400) * 0.5663;
    }
    printf("%.1f\n", total);
    return 0;
}
//  P1424
#include <stdio.h>
int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    int weeks = n / 7;
    int remainder = n % 7;
    long long total = weeks * 5 * 250;
    for (int i = 0; i < remainder; i++) {
        int day = (x + i - 1) % 7 + 1;
        if (day <= 5) total += 250;
    }

    printf("%lld\n", total);
    return 0;
}
