#include <stdio.h>

int main() {
    int n, t;
    long long A;  
    int ans = 0;

    scanf("%d", &n);
    while (n--) {
        long long int_part, frac_part;
        scanf("%lld.%lld %d", &int_part, &frac_part, &t);
        A = int_part * 1000000 + frac_part;  

        for (int i = 1; i <= t; i++) {
            ans ^= (int)((i * A) / 1000000);
        }
    }

    printf("%d\n", ans);
    return 0;
}