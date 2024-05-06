class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);                       /* dp[i]：i 个节点可以组成 dp[i] 种二叉搜索树 */
                                                        /* 初始化为 0，保证累加值没有问题 */
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {              /* 头节点(j)不同的情况的总和 */
                dp[i] += dp[j - 1] * dp[i - j];         /* 左子树 × 右子树 */
            }

        }
        return dp[n];
    }
};