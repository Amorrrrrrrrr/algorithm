class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int> (s.size() + 1, 0));
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {       /* 注意 dp 数组的大小和字符比较的区别 */
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[t.size()][s.size()] == s.size();
    }
};