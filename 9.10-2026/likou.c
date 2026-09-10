#define _CRT_SECURE_NO_WARNINGS 
int lengthOfLongestSubstring(char* s) {
    int last[256];           // 记录每个字符最近出现的位置
    for (int i = 0; i < 256; i++) last[i] = -1;

    int l = 0, ans = 0;
    for (int r = 0; s[r]; r++) {
        unsigned char c = s[r];
        if (last[c] >= l) l = last[c] + 1;
        last[c] = r;
        int len = r - l + 1;
        if (len > ans) ans = len;
    }
    return ans;
}