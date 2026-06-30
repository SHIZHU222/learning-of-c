bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    for (int len = 1; len <= n / 2; len++) {  // 枚举子串长度
        if (n % len != 0) continue;            // 必须能整除

        bool ok = true;
        for (int i = len; i < n; i++) {
            if (s[i] != s[i % len]) {          // 和第一个子串逐位比较
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}
//
bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    char t[2 * n + 1];          // 拼接: s + s
    strcpy(t, s);
    strcat(t, s);

    // 去掉首尾字符，在 t+1 到 t+2n-2 中查找 s
    return strstr(t + 1, s) != NULL && strstr(t + 1, s) < t + n;
}