#define _CRT_SECURE_NO_WARNINGS 
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[p--] = nums1[i--];
        else
            nums1[p--] = nums2[j--];
    }
}