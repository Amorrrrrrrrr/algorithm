class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));                   /* dp[i][0]: 持有股票状态
                                                                                     * dp[i][1]: 保持卖出股票的状态
                                                                                     * dp[i][2]: 今天卖出股票
                                                                                     * dp[i][3]: 今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
                                                                                     */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;                                                               /* 非法定义的初始化可由递推公式反推出来 */
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++) {                                   /* 状态更新递推 */
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1] - prices[i]), dp[i - 1][3] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};