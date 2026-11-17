#define _CRT_SECURE_NO_WARNINGS 
bool canJump(int* nums, int numsSize) {
    int goal = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (i + nums[i] >= goal)
            goal = i;          /* 这个位置能到目标，目标左移 */
    }
    return goal == 0;
}