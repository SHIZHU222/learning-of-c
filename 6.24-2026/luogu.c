//P5417
#include <stdio.h>
int main()
{
    double m, h;
    scanf("%lf %lf", &m, &h);
    double bmi = m / (h * h);
    if (bmi < 18.5)
        printf("Underweight");
    else if (bmi < 24)
        printf("Normal");
    else
        printf("%g\nOverweight", bmi);

    return 0;
}
//P5716
#include <stdio.h>
int main()
{
    int y = 0, m = 0;
    scanf("%d %d", &y, &m);
    int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        printf("29");
    else
        printf("%d", days[m]);
    return 0;

}
//还可以直接使用分支结构来做
#include <stdio.h>

int main() {
    int y, m;
    scanf("%d %d", &y, &m);

    if (m == 2) {
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            printf("29");
        else
            printf("28");
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        printf("30");
    else
        printf("31");

    return 0;
}
//P5717
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) { int t = a; a = b; b = t; }
    if (a > c) { int t = a; a = c; c = t; }
    if (b > c) { int t = b; b = c; c = t; }
    if (a + b <= c) {
        printf("Not triangle");
        return 0;
    }
    if (a * a + b * b > c * c)
        printf("Acute triangle\n");
    else if (a * a + b * b == c * c)
        printf("Right triangle\n");
    else
        printf("Obtuse triangle\n");
    if (a == b || b == c)
        printf("Isosceles triangle\n");
    if (a == b && b == c)
        printf("Equilateral triangle\n");


    return 0;
}
//P1046
#include <stdio.h>
int main()
{
    int apple[11];
    int reach, count;

    for (int i = 0; i < 10; i++)
        scanf("%d", &apple[i]);
    scanf("%d", &reach);
    for (int i = 0; i < 10; i++)
        if (apple[i] <= reach + 30)
            count++;
    printf("%d", count);

    return 0;
}
