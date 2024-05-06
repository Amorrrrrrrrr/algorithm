class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }

        return dp[target] == target;

    }
};

/*
 * dp[j] = max(dp[j - nums[i]] + values[i], dp[j]);     -> ��ô��ı��������װ���ټ�ֵ����Ʒ                -> ��һ��װ��
 * dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);       -> ��ô��ı��������װ������������Ʒ                -> ��һ��װ��
 * dp[j] = max(dp[j - nums[i]] + 1, dp[j]);             -> ��ô��ı��������װ���ٸ���Ʒ                    -> ��һ��װ��
 * dp[j] += dp[j - nums[i]];                            -> ��ô��ı���װ���ж����ַ�������ʼ����dp[0] = 1�� -> һ��װ����δװ��ʱ���س�ʼֵ��
 */