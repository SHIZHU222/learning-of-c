//P4956
#include <stdio.h>
int main()
{
    int N = 0;
    scanf("%d", &N);
    for (int X = 100; X >= 1; X--) {
        int reback = N - 364 * X;
        if (reback % 1092 == 0) {
            int K = reback / 1092;
            if (K > 0) {
                printf("%d\n%d\n", X, K);
                return 0;
            }
        }
    }
    return 0;
}
//P5726
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];//这个就是个人选择了，我比较喜欢用数组做这个题，对于我后来大数值的编程回带来一个更便利的条件。
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int max = a[0], min = a[0], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] > max)max = a[i];
        if (a[i] < min)min = a[i];
    }
    double score = (double)(sum - max - min) / (n - 2);//其实写在这我就后悔了，其实我应该抛弃掉数组的写。
    printf("%.2f", score);
    return 0;
}
//P1075
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 2;
    while (n % i != 0)
        i++;
    printf("%d", n / i);
    return 0;
}
//P1720
#include <stdio.h>
#include <math.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    double first = (1.0 + sqrt(5.0)) / 2.0;
    double second = (1.0 - sqrt(5.0)) / 2.0;
    double numerator = pow(first, n) - pow(second, n);//math库中的，pow函数是有底数和指数一起来结合的，毕竟是斐波那契数列。
    double Fn = numerator / sqrt(5.0);//懒得吐槽为什么要用公式法去写这个由一堆参量来表明的题目
    printf("%.2f", Fn);//我还以为很难，但还是很简单。（小小臭屁一下）

    return 0;
}
