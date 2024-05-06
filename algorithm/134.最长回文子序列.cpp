class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));     /* dp[i][j]: 从 i 到 j 这个范围内([i,j])的最长回文子序列的长度为dp[i][j] */
        for (int i = 0; i < s.size(); i++) {                            /* 回文问题的初始化 */
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {                       /* 遍历顺序 */
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {                                     /* 分两种情况 */
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};