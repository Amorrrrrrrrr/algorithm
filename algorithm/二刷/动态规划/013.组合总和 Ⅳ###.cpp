class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j < nums[i] || dp[j] >= INT_MAX - dp[j - nums[i]]) continue;        /* 注意：两个越界问题 */

                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

/* 
 * 完全背包求组合和排列问题：
 *  - 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
 *  - 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
 * 完全背包求最多和最少问题：
 *  - 最多是正常的。
 *  - 最少是一定装满的。
 */