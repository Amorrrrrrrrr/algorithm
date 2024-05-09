/* 找到比当前数尽量小的大数 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        for (int i = nums.size() - 2; i >= 0; i--) {                /* 从后先前找，实现尽量小 */     
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; j--) {         /* 再从后先前找，实现尽量小 */
                    if (nums[j] > nums[i]) {
                        swap(nums[j], nums[i]);                     /* 尽量小步骤1：交换 */
                        sort(nums.begin() + i + 1, nums.end());     /* 尽量小步骤2：升序排列 */
                        return;
                    }
                } 
            }
        }

        sort(nums.begin(), nums.end());                             /* 当前数为最大数逻辑 */
    }
};