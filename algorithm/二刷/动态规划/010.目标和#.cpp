class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum < abs(target)) return 0;
        if ((sum + target) % 2 == 1) return 0;
        int key = (sum + target) / 2;

        vector<int> dp(key + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = key; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[key];
    }
};