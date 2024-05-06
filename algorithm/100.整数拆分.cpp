class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);                                          /* dp[i]: �� i ���в�ֵõ������ĳ˻����� dp[i] */
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {                          /* �Ż� */
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);    /* j * (i - j)����ֳ�������
                                                                           j * dp[i - j]����ֳ� 3 ���������� */
            }
        }
        return dp[n];
    }
};