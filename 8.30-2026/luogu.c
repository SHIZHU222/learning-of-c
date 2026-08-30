#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void) {
    int q;
    char doc[20005] = { 0 };
    char tmp[20005];

    scanf("%d %s", &q, doc);

    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            char str[105];
            scanf("%s", str);
            strcat(doc, str);
            printf("%s\n", doc);
        }
        else if (op == 2) {
            int a, b;
            scanf("%d %d", &a, &b);
            strncpy(tmp, doc + a, b);
            tmp[b] = '\0';
            strcpy(doc, tmp);
            printf("%s\n", doc);
        }
        else if (op == 3) {
            int a;
            char str[105];
            scanf("%d %s", &a, str);
            int len = strlen(str);
            memmove(doc + a + len, doc + a, strlen(doc + a) + 1);
            strncpy(doc + a, str, len);
            printf("%s\n", doc);
        }
        else if (op == 4) {
            char str[105];
            scanf("%s", str);
            char* p = strstr(doc, str);
            if (p) printf("%d\n", (int)(p - doc));
            else   printf("-1\n");
        }
    }
    return 0;
}