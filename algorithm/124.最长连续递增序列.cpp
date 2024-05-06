

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);                                     /* dp[i]: �� nums[i] Ϊ��β����������������еĳ��� */
                                                                            /* Ĭ�ϳ�ʼ����Ϊ 1�����ٰ��� nums[i]��*/
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) dp[i] = dp[i - 1] + 1;               /* ���� */
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};