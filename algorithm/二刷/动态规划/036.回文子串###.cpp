class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        int ret = 0;

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            ret++;
        }

        for (int i = s.size() - 1; i >= 0; i--) {               /* 注意遍历顺序 */
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == s[i]) {
                    if (j - i == 1) {
                        dp[i][j] = true;
                        ret++;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                        if (dp[i][j] == true) 
                            ret++;
                    }
                }
            }
        }

        return ret;
    }
};