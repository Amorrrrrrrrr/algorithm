class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));                       /* dp[i][j]: 从 0，0 走到 i，j 有多少种不同的路径 */
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break;                             /* 如何初始化很重要 */
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {                                   
                if (obstacleGrid[i][j] == 1) continue;                      /* 递推公式注意条件 */
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};