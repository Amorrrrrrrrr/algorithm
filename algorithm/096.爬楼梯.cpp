class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(n + 1);                  /* dp[i]: 爬到第 i 阶台阶有 dp[i] 种方法 */
        dp[0] = 0;                              /* 无意义 */
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};