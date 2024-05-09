/* 每一步取最大的覆盖范围（每遍历一个元素的时候尽可能地去增加它的覆盖范围 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = nums[0];
        for (int i = 0; i <= next; i++) {               /* 只能在覆盖范围内移动*/
            if (next >= nums.size() - 1) return true;

            next = max(next, i + nums[i]);
        }
        return false;
    }
};