//P1425
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int start = a * 60 + b;
    int end = c * 60 + d;
    int all = end - start;
    printf("%d %d", all / 60, all % 60);

    return 0;
}
//P1421
#include <stdio.h>
int main()
{
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    int zong = a * 10 + b;
    printf("%d", zong / 19);
    return 0;
}
//P5707
#include <stdio.h>
int main()
{
    int s = 0, v = 0;
    scanf("%d%d", &s, &v);
    int paytime = (s + v - 1) / v;//向下取整，丢掉余数，进一
    int all = paytime + 10;
    int depart = 480 - all;
    if (depart < 0)
        depart += 1440;
    int h = depart / 60;
    int w = depart % 60;
    printf("%02d:%02d", h, w); //c语言特有的设置占位符
    return 0;

}
//P3954
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a < 0 || b < 0 || c < 0)//我想表达的是我给他做一个变量范围的限定，感觉还是没有做好
        return 1;
    int zongchengji = a * 0.2 + b * 0.3 + c * 0.5;
    if (zongchengji < 0 || zongchengji > 100)
        return 1;
    printf("%d", zongchengji);
    return 0;
}
//优化
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < 0 || a > 100 || b < 0 || b > 100 || c < 0 || c > 100)
        return 1;
    int zongchengji = (a * 2 + b * 3 + c * 5) / 10;
    printf("%d\n", zongchengji);
    return 0;
}
//暂且到这