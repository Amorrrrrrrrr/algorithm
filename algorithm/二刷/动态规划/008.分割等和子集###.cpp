class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }

        return dp[target] == target;

    }
};

/*
 * dp[j] = max(dp[j - nums[i]] + values[i], dp[j]);     -> 这么大的背包最多能装多少价值的物品                -> 不一定装满
 * dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);       -> 这么大的背包最多能装多少质量的物品                -> 不一定装满
 * dp[j] = max(dp[j - nums[i]] + 1, dp[j]);             -> 这么大的背包最多能装多少个物品                    -> 不一定装满
 * dp[j] += dp[j - nums[i]];                            -> 这么大的背包装满有多少种方法（初始化：dp[0] = 1） -> 一定装满（未装满时返回初始值）
 */