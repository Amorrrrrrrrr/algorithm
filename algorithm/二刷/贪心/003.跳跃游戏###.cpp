/* ̰�� */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];

        for (int i = 0; i <= maxIndex; i++) {               /* maxIndex �ǿ��Դﵽ�� */
            maxIndex = max(maxIndex, i + nums[i]);
            if (maxIndex >= nums.size() - 1) return true;
        }
        return false;
    }
};