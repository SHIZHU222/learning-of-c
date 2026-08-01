#define _CRT_SECURE_NO_WARNINGS 
int expand(char* s, int l, int r) {
    while (l >= 0 && s[r] && s[l] == s[r]) l--, r++;
    return r - l - 1;                          // 回文长度
}

char* longestPalindrome(char* s) {
    int start = 0, maxLen = 1, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int odd = expand(s, i, i);              // 奇数长度回文
        int even = expand(s, i, i + 1);         // 偶数长度回文
        int cur = odd > even ? odd : even;
        if (cur > maxLen) {
            maxLen = cur;
            start = i - (cur - 1) / 2;          // 回推起始位置
        }
    }
    s[start + maxLen] = '\0';                   // 截断返回
    return s + start;
}
//2
char* longestPalindrome(char* s) {
    int n = strlen(s), start = 0, maxLen = 1;
    char dp[1005] = { 0 };                        // 布尔型标记

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (s[i] == s[j] && (j - i < 3 || dp[j - 1]))
                dp[j] = 1;
            else
                dp[j] = 0;
            if (dp[j] && j - i + 1 > maxLen)
                start = i, maxLen = j - i + 1;
        }
    }
    s[start + maxLen] = '\0';
    return s + start;
}