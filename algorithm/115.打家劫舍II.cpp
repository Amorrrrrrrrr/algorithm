/* 打家劫舍 + 不考虑首/尾元素 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.size() - 1, 0);                          /* dp[i]: 考虑下标 i（包含） 所能偷到的最大的金币为 dp[i] */
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i <  nums.size() - 1; i++) {                 /* 情况一(0~size-2) */
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        int ret1 = dp[nums.size() - 2];

        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        for (int i = 2; i <  nums.size() - 1; i++) {                 /* 情况二(1~size-1) */
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + 1]);
        }

        return max(ret1, dp[nums.size() - 2]);
    }
};

/* 标准答案 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // 情况二
        int result2 = robRange(nums, 1, nums.size() - 1); // 情况三
        return max(result1, result2);
    }
    // 198.打家劫舍的逻辑
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};