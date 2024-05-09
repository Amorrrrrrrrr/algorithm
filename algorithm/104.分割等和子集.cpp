
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        int target = sum/2;

        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {                       /* j 必须 >= nums[i] */
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;                              /* 物品的重量和价值是相同的 */
        return false;
    }
};