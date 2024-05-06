class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);                       /* dp[i]��i ���ڵ������� dp[i] �ֶ��������� */
                                                        /* ��ʼ��Ϊ 0����֤�ۼ�ֵû������ */
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {              /* ͷ�ڵ�(j)��ͬ��������ܺ� */
                dp[i] += dp[j - 1] * dp[i - j];         /* ������ �� ������ */
            }

        }
        return dp[n];
    }
};