#define _CRT_SECURE_NO_WARNINGS 
bool isValid(char* s) {
    int n = (int)strlen(s);
    char* stk = (char*)malloc(n + 1);
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(')      stk[top++] = ')';
        else if (c == '[') stk[top++] = ']';
        else if (c == '{') stk[top++] = '}';
        else {
            if (top == 0 || stk[--top] != c) {
                free(stk);
                return false;
            }
        }
    }

    bool ok = (top == 0);
    free(stk);
    return ok;
}