//P5708
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double p = (a + b + c) / 2.0;
    double mianji = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1f", mianji);
    return 0;
}
//P5706
#include <stdio.h>
int main()
{
    float t = 0;
    int n = 0;
    scanf("%f %d", &t, &n);
    float yinliao = t / n;
    int beizi = n * 2;
    printf("%.3f\n%d\n", yinliao, beizi);
    return 0;
}
//P2029
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    double v = 3.14 * b * b * a;
    int n = (int)ceil(20000.0 / v);//这里进行了一个向上取整，用的是celi函数celi函数的意思上像无穷处取整。
    printf("%d", n);//celi函数原型是 double celi(double x)这里强制转换为int整形。
    return 0;//强制转换的方法就是在需要的变量表达式前面加上目标形式（int）xxx这种
    //向上取整也可以这么做（20000 + v - 1）但有点难以记忆，所以采取更加简便的celi函数
}
//P4414
#include <stdio.h>
int main()
{
    int a, b, c;
    char shunxu[4];
    scanf("%d %d %d", &a, &b, &c);
    scanf("%s", shunxu);
    if (a > b) { int t = a; a = b; b = t; }//进行一个比较如果a>b就往后排，下面依次类推
    if (a > c) { int t = a; a = c; c = t; }//=为赋值把a的值赋给B
    if (b > c) { int t = b; b = c; c = t; }
    for (int i = 0; i < 3; i++) {//从0到2进行一个循环，如果第i个字母为A就输出a
        if (shunxu[i] == 'A')
            printf("%d", a);
        else if (shunxu[i] == 'B')//如果为B就输出b
            printf("%d", b);
        else printf("%d", c);//否则就输出c
        if (i < 2) printf(" ");//加上空格
    }
    printf("\n");//换行
    return 0;
}
//P5715
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) { int t = a; a = b; b = t; }
    if (a > c) { int t = a; a = c; c = t; }
    if (b > c) { int t = b; b = c; c = t; }
    printf("%d %d %d", a, b, c);
    return 0;
}