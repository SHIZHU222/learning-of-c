#define _CRT_SECURE_NO_WARNINGS 
int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0;
    int jumps = 0, i = 0, reach = 0, next = 0;
    while (reach < numsSize - 1) {
        jumps++;
        for (; i <= reach; i++) {
            if (i + nums[i] > next) next = i + nums[i];
        }
        reach = next;
    }
    return jumps;
}