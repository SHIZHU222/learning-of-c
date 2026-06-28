//P5718
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a, min = 1001;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < min) min = a;
    }
    printf("%d", min);
    return 0;
}
