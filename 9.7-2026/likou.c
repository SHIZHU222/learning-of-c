#define _CRT_SECURE_NO_WARNINGS '
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, cur = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;      // 去重
            if (nums[i] == nums[i - 1] + 1) cur++;
            else { ans = max(ans, cur); cur = 1; }
        }
        return max(ans, cur);
    }
};