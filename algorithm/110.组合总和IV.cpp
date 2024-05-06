/* 完全背包+排列数 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);                                   /* dp[j]: 装满容量为 j 的背包一共有 dp[j] 种方法 */
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

/* 拓展：爬 n 阶楼梯（进阶版） */