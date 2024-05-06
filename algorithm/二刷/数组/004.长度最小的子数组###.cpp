/* ˫ָ�뷨����������˼�룩 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0;
        int sum = 0;
        int ret = INT_MAX;
        for (int fast = 0; fast < nums.size(); fast++) {
            sum += nums[fast];
            while (sum >= target) {
                ret = min(ret, fast - slow + 1);
                sum -= nums[slow];
                slow++;
            }
        }
        if (ret == INT_MAX) return 0;
        return ret;

    }
};

/* �������ڵľ���֮�����ڸ��ݵ�ǰ�����кʹ�С����������ϵ��������е���ʼλ�á��Ӷ���O(n^2)�����ⷨ��ΪO(n)�� */