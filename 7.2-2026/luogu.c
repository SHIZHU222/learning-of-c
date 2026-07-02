//P1420
#include <stdio.h>
int main()
{
    int n, max, length;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            length++;
            if (length > max) max = length;
        }
        else {
            length = 1;
        }
    }
    printf("%d", max);
    return 0;
}
// P5725
#include <stdio.h>
int main()
{
    int n, num = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%02d", num++);//printf有补零的功能，完成这道题需要补零去形成一个完整的正方形。
        printf("\n");
    }
    printf("\n");
    num = 1;
    for (int i = 0; i < n; i++) {//很显而易见，这个是三角形的写作。
        for (int j = 0; j < (n - i - 1) * 2; j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("%02d", num++);
        printf("\n");
    }
    return 0;
}
//