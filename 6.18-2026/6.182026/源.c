//B2004
//#include <stdio.h>
//int main()
// {   int a, b, c = 0;
//  scanf("%d%d%d", &a, &b, &c);
//  printf("%8d%8d%8d", a, b, c);
//  return 0;
//  }
//报错的原因是因为没有在各个分离之中打上空格导致题目识别的问题，换成一下这个就明确了
//#include <stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    printf("%8d %8d %8d\n", a, b, c);
//    return 0;
//}
//纯粹的c语言也能带人走上巅峰
//B2007
//#include <stdio.h>
//int main()
//{
//    int a, b = 0;
//    scanf("%d%d", &a, &b);
//    printf("%d", a + b);
//    return 0;
//}
//B2003
//#include <stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);
//    printf("%d", b);
//    return 0;
//}
//B2064
//#include <stdio.h>
//int main()
//{
//    int n, a, i;
//    int f[31];
//    f[1] = 1;
//    f[2] = 1;
//    i = 3;
//    while (i <= 30) {
//        f[i] = f[i - 1] + f[i - 2];
//        i = i + 1;
//    }
//    scanf("%d", &n);
//    i = 0;
//    while (i < n) {
//        scanf("%d", &a);
//        printf("%d\n", f[a]);
//        i = i + 1;
//    }
//    return 0;
//}
//B2005
#include <stdio.h>
int main()
{
    char ch;
    scanf_s("%c", &ch);
    printf("  %c\n", ch);
    printf(" %c%c%c\n", ch, ch, ch);
    printf("%c%c%c%c%c\n", ch, ch, ch, ch, ch);
    return 0;
}
//字符类型随意设置参量名