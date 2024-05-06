/* ��ȫ���� */
class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        for (int i = 1; i <= sqrt(n); i++) {
            if (i * i <= n) square.push_back(i * i);
        }

        vector<int> dp(n + 1, INT_MAX - 1);                 /* dp[j]: װ������Ϊ j �ı���������ƷΪ dp[j] */
        dp[0] = 0;
        for (int i = 0; i < square.size(); i++) {
            for (int j = square[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - square[i]] + 1);
            }
        }

        return dp[n];
    }
};


/* ��׼�� */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};