class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, 0));                           /* 买卖 k 次 */
        for (int i = 0; i < k; i++) {                                                           /* 循环初始化 */
            dp[0][i * 2] = -prices[0];
            dp[0][i * 2 + 1] = 0;
        }

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], 0 - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            for (int j = 1; j < k; j++) {                                                       /* 循环递推 */
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] - prices[i]);
                dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] + prices[i]);
            }

        }

        return dp[prices.size() - 1][2 * k - 1];
    }
};