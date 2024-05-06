/* ��ȡ��������Сֵ����ѭ��ȡ���Ǹ�����Сֵ */

class Solution {
    static bool cmp(int a, int b) {                                 /* �ȽϺ��� */
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);                        /* ���վ���ֵ�Ӵ�С���� */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;                /* ���жϴ���--�����Ч�� */

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += nums[i];
        }

        return result;
    }
};