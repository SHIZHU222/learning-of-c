//P1035
#include <stdio.h>
int main()
{
    int k, n = 1;
    double sum = 0.0;
    scanf("%d", &k);
    while (sum <= k) {
        sum += 1.0 / n;
        n++;
    }
    printf("%d", n - 1);
    return 0;
}
//P2669
#include <stdio.h>
int main()
{
    int k = 0, n = 0;
    scanf("%d", &k);
    int jieduan = 1, tianshu = 1;
    for (int i = 0; i < k; i++) {
        n += jieduan;
        tianshu--;
        if (tianshu == 0) {
            jieduan++;
            tianshu = jieduan;
        }
    }
    printf("%d", n);
    return 0;
}
//  P5722
#include <stdio.h>
int main()
{
    int n, total = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    printf("%d", total);
    return 0;
}
//P1423
#include <stdio.h>
int main()
{
    double s = 0, juli = 2.0, juli2 = 0.0;
    int bushu = 0;
    scanf("%lf", &s);
    while (juli2 <= s) {
        juli2 += juli;
        bushu++;
        juli *= 0.98;
    }
    printf("%d", bushu);
    return 0;
}
//P5723
#include <stdio.h>
int main()
{
    int l, zshu = 0, geshu = 0, shu = 2;
    scanf("%d", &l);
    while (1) {
        int num = 1;
        for (int i = 2; i * i <= shu; i++) {
            if (shu % i == 0) {
                num = 0;
                break;
            }
        }
        if (num) {
            if (zshu + shu > l) break;
            zshu += shu;
            geshu++;
            printf("%d\n", shu);
        }
        shu++;
    }
    printf("%d\n", geshu);
    return 0;
}