#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last[256];
    memset(last, -1, sizeof(last));

    int left = 0, ans = 0;
    for (int i = 0; s[i]; i++) {
        unsigned char c = s[i];
        if (last[c] >= left)
            left = last[c] + 1;
        last[c] = i;
        int len = i - left + 1;
        if (len > ans) ans = len;
    }
    return ans;
}
#define _CRT_SECURE_NO_WARNINGS 