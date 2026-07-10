//P1614
#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ai[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ai[i]);
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += ai[i];
    int min = sum;
    for (int i = m; i < n; i++) {
        sum = sum + ai[i] - ai[i - m];
        if (sum < min) min = sum;
    }

    printf("%d\n", min);
    return 0;
}