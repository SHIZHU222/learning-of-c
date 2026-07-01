//P1307
#include <stdio.h>
int main()
{
    int n, rev = 0;
    scanf("%d", &n);
    int sign = n < 0 ? -1 : 1;
    n = n * sign;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf("%d", rev * sign);
    return 0;
}
//P5724
#include <stdio.h>
int main()
{
    int n, a;
    int max = 0, min = 1000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > max) max = a;
        if (a < min) min = a;
    }
    printf("%d", max - min);
    return 0;
}