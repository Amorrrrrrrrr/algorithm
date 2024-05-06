class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));                   /* dp[i][0]: ���й�Ʊ״̬
                                                                                     * dp[i][1]: ����������Ʊ��״̬
                                                                                     * dp[i][2]: ����������Ʊ
                                                                                     * dp[i][3]: ����Ϊ�䶳��״̬�����䶳��״̬���ɳ�����ֻ��һ�죡
                                                                                     */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;                                                               /* �Ƿ�����ĳ�ʼ�����ɵ��ƹ�ʽ���Ƴ��� */
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++) {                                   /* ״̬���µ��� */
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1] - prices[i]), dp[i - 1][3] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};