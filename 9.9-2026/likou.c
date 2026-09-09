#define _CRT_SECURE_NO_WARNINGS 
int maxArea(int* height, int n) {
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
        int h = height[l] < height[r] ? height[l] : height[r];
        int area = h * (r - l);
        if (area > ans) ans = area;
        if (height[l] < height[r]) l++;
        else r--;
    }
    return ans;
}