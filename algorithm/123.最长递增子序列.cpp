
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);                                     /* dp[i]: �� nums[i] Ϊ��β������������еĳ��� */
                                                                            /* Ĭ�ϳ�ʼ����Ϊ 1�����ٰ��� nums[i]��*/
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};