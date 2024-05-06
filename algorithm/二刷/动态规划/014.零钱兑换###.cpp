class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);                /* 初始化问题 */
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];     /* 返回值问题 */
    }
};

/* 特点：装满才有效 */