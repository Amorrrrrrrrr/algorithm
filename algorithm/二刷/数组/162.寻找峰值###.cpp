/* ���ֲ��ҷ� + ̰�� */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {                                  /* �� l = r ʱ�����ҵ���ֵ */
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;      /* ��Ϊ mid ��ͨ������ȡ������õ��ģ��� l < r ������¿϶���������ھ� */
            else right = mid;
        }

        return left;
    }
};