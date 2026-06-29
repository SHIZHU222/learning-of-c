//P5721
#include <stdio.h>
int main()
{
    int n, x = 1;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {//这里我原先采取的是j<=i,发现打印出来的东西在第一行多一位，与此改变即ac
            printf("%02d", x++);
        }
        printf("\n");
    }
    return 0;
}
//P5720
#include <stdio.h>
int main()
{
    int a = 0, day = 1;
    scanf("%d", &a);
    while (a > 1) {//其实用for循环也可以就是像上面呢样嵌套就可以，这种题目的底层逻辑是一样的；但是while循环使用
        a /= 2;//最简单也最快，因为其一直循环直到结束为止。才在这里最适合。
        day++;
    }
    printf("%d", day);
    return 0;
}
//P5719
#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            sum1 += i;
            count1++;
        }
        else {
            sum2 += i;
            count2++;
        }
    }
    printf("%.1f %.1f", 1.0 * sum1 / count1, 1.0 * sum2 / count2);//这里做了一个整型和浮点型的转换
    return 0;
}
//这道题先re了一次，在ac的，实际上是犯了一个低级错误。
//P1980
#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int count = 0;
    for (int factor = 1; factor <= n; factor *= 10) {//做出这样一个循环，计算每一个数字位上到底存不存在x
        int high = n / (factor * 10);//当前位左边的数字
        int cur = (n / factor) % 10;//当前位数上的数字
        int low = n % factor;//当前位右边的数字

        if (high == 0 && x == 0) break;   // x=0时跳过最高位  
        count += high * factor;//不考虑其他的余数只考虑次数问题
        if (cur > x)//这里进行一个余数的修正
            count += factor;
        else if (cur == x)
            count += low + 1;
    }
    printf("%d", count);
    return 0;
}
//可惜的是，这道题还是没有达到完整的ac还是出现了wa错误
//然后发现是这句代码的问题 count += high * factor;从一轮计算成了两轮数字。
//改为if (x == 0)
//count += (high - 1) * factor;
//else
//count += high * factor;
//便彻底的ac了
//那么问题来了，有没有更好的解决这道题的方法呢？
//暴力枚举一试
#include <stdio.h>
int main()
{
    int n, x, count = 0;
    char ch = x + '0';
    scanf("%d %d", &n, &x);

    for (int i = 1; i <= n; i++) {
        char s[10];
        sprintf(s, "%d", i);
        for (int j = 0; s[j]; j++)
            if (s[j] == ch)
                count++;
    }
    printf("%d", count);
    return 0;
}
//WA遂寻找原因。
//改正
#include <stdio.h>
int main()
{
    int n, x, count = 0;
    scanf("%d %d", &n, &x);

    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t) {
            if (t % 10 == x) count++;
            t /= 10;
        }
    }
    printf("%d", count);
    return 0;
}
//啊，但是怎么说呢，实践测试出来，暴力枚举法还是慢于第一种解法。
