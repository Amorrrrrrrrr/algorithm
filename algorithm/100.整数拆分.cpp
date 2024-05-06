class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);                                          /* dp[i]: 对 i 进行拆分得到的最大的乘积就是 dp[i] */
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {                          /* 优化 */
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);    /* j * (i - j)：拆分成两个数
                                                                           j * dp[i - j]：拆分成 3 个数及以上 */
            }
        }
        return dp[n];
    }
};