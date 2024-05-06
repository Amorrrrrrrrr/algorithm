class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));


        for (int i = 0; i < strs.size(); i++) {
            int zero = 0;
            int one = 0;
            for (int k = 0; k < strs[i].size(); k++) {
                if (strs[i][k] == '0') zero++;
                else one++;
            }
            for (int a = m; a >= zero; a--) {
                for (int b = n; b >= one; b--) {
                    dp[a][b] = max(dp[a][b], dp[a - zero][b - one] + 1);
                }
            }
        }

        return dp[m][n];
    }
};