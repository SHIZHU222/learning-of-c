//P5712
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    if (a < 0)
        return 0;
    if (a <= 1)
        printf("Today, I ate %d apple.", a);
    else
        printf("Today, I ate %d apples.", a);
    return 0;
}
//P5710
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);

    int p1 = (a % 2 == 0);
    int p2 = (a >= 4 && a <= 12);
    printf("%d %d %d %d", p1 && p2, p1 || p2, p1 != p2, !p1 && !p2);
    return 0;
}
//P5713
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);

    if (a < 0)
        return 0;
    if (a < 6)
        printf("Local");
    else
        printf("Luogu");
    return 0;
}
//最简单的解法是这个，但我想用一个循环结构直接计算得出来，这还要我手动去算太麻烦了
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int local = 0;
    for (int i = 0; i < n; i++)          // 外层：每题
        for (int j = 0; j < 5; j++)      // 内层：每题 5 分钟
            local++;

    int luogu = 11;                       // 一次性建团队
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)      // 每题 3 分钟
            luogu++;

    if (local < luogu)
        printf("Local\n");
    else
        printf("Luogu\n");

    return 0;
}
//p1085  不高兴的津津，我也不高兴了，最烦这种隐藏自己是数据结构的题了，不想排序
#include <stdio.h>

int main()
{
    int max = 0, day = 0, a, b;

    for (int i = 1; i <= 7; i++)
    {
        scanf("%d %d", &a, &b);
        int sum = a + b;
        if (sum > max)
        {
            max = sum;
            day = i;
        }
    }

    if (max <= 8)
        printf("0\n");
    else
        printf("%d\n", day);

    return 0;
}
//当然是最喜欢用的循环语句啦
//当时想了半天是用循环语句来写还是用分支语句来写，当然是我们最最最简单的分支语句啊，


