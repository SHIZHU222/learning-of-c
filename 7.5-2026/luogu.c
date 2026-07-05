//P1428
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ai[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ai[i]);
    }//储存这个数组的值
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < i; j++) {
            if (ai[j] < ai[i]) {
                degree++;
            }
        }
        printf("%d ", degree);
    }
    return 0;
}
//P1427
#include <stdio.h>
int main()
{
    int n = 0, x;
    int a[100];
    while (1) {
        scanf("%d", &x);
        if (x == 0)
            break;
        a[n] = x;
        n++;
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", a[i]);//带上空格便于后续分辨
    }
    return 0;
}
//P5727
#include <stdio.h>
int main()
{
    int n;
    int count = 0;
    int a[200];
    scanf("%d", &n);
    a[count++] = n;
    while (n != 1) {
        if (n % 2 == 1)
            n = n * 3 + 1;
        else
            n = n / 2;
        a[count++] = n;
    }
    for (int i = count - 1; i >= 0; i--)
        printf("%d ", a[i]);
    return 0;
}
//P