class Solution {
public:
    int countSubstrings(string s) {
                                                                
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));   /* dp[i][j]: 从 i 到 j 这个范围内([i,j])的子串是不是一个回文串 */
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {                           /* 遍历顺序取决于递推公式 */
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {                                         /* 分三种情况考虑 */
                    if (j - i <= 1) {                                       /* 情况1 和 情况2 */
                        dp[i][j] = true;
                        result++;
                    }
                    else {
                        if (dp[i + 1][j - 1] == true) {                     /* 情况3 */
                            dp[i][j] = dp[i + 1][j - 1];
                            result++;
                        }

                    }
                }
            }
        }
        return result;
    }
};