//P1888
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) { int t = a; a = b; b = t; }
    if (a > c) { int t = a; a = c; c = t; }
    if (b > c) { int t = b; b = c; c = t; }
    int x = a, y = c;
    while (y != 0) { //欧几里得算法，使得约分
        int t = y;
        y = x % y;
        x = t;
    }
    printf("%d/%d", a / x, c / x);
    return 0;
}
//P1909
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int b, c, d, e, f, g;
    scanf("%d %d %d %d %d %d", &b, &c, &d, &e, &f, &g);
    int pay1 = ((n + b - 1) / b) * c;
    int pay2 = ((n + d - 1) / d) * e;
    int pay3 = ((n + f - 1) / f) * g;
    int money = pay1;
    if (money > pay2)
        money = pay2;
    if (money > pay3)
        money = pay3;
    printf("%d", money);
    return 0;
}
//P1055
#include <stdio.h>
int main()
{
    char bianma[14];
    scanf("%s", &bianma);
    int sum = 0, k = 1;
    for (int i = 0; i < 12; i++) {
        if (bianma[i] != '-') {
            sum += (bianma[i] - '0') * k;
            k++;
        }
    }
    int mod = sum % 11;
    char right = (mod == 10) ? 'X' : ('0' + mod);
    if (bianma[12] == right)
        printf("Right");
    else {
        bianma[12] = right;
        printf("%s", bianma);
    }
    return 0;
}

