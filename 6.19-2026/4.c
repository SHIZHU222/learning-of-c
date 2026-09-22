//B2025
#include <stdio.h>
int main()
{
    printf("  *\n");
    printf(" ***\n");
    printf("*****\n");
    printf(" ***\n");
    printf("  *\n");
    return 0;
}
//P5703
#include <stdio.h>
int main()
{
    int a, b = 0;
    scanf("%d%d", &a, &b);
    printf("%d", a * b);
    return 0;
}
//P5704
#include <stdio.h>
int main()
{
    char as;
    scanf("%c", &as);
    printf("%c", as - 32);
    return 0;
}
//P5705#include <stdio.h>
#include <string.h>
int main()
{
    char s[10];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", s[i]);
    return 0;
}